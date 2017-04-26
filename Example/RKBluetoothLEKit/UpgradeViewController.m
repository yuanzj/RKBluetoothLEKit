//
//  UpgradeViewController.m
//  RokyinfoBLEDemo
//
//  Created by apple on 16/5/13.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import "UpgradeViewController.h"
#import "RKAppDelegate.h"
#import <RKBluetoothLE_iOS/UpgradeManager.h>
#import <CocoaSecurity/CocoaSecurity.h>
#import <AudioToolbox/AudioToolbox.h>

static SystemSoundID shake_sound_male_id = 0;

//#define BUILD_FILE_MODEL 1

@interface UpgradeViewController (){
    
    BOOL isSuccess;
    
    int successCount;
    
    int errorCount;
    
    NSDate *wholeStartTime;
    
    RACDisposable *mRACDisposable,*playSound,*upgradeManagerRACDisposable;
    
    NSData* fileData;
    
}

@property (weak,nonatomic) IBOutlet UITextField *fileSize;
@property (weak,nonatomic) IBOutlet UITextField *version;
@property (weak,nonatomic) IBOutlet UITextField *singlePackageSize;
@property (weak,nonatomic) IBOutlet UISwitch    *isForceUpgradeMode;

@property (weak,nonatomic) IBOutlet UISwitch    *isAutoMode;

@property (weak,nonatomic) IBOutlet UIButton    *btnReboot;

@property (weak,nonatomic) IBOutlet UILabel     *message;
@property (weak,nonatomic) IBOutlet UILabel     *percentage;
@property (weak,nonatomic) IBOutlet UILabel     *time;
@property (weak,nonatomic) IBOutlet UILabel     *remainingTime;

@property (weak,nonatomic) IBOutlet UILabel     *succressCountLab;

@end

@implementation UpgradeViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    isSuccess = NO;
    self.time.text = [NSString stringWithFormat:@"用时：%d 秒",0] ;
    self.succressCountLab.text = [NSString stringWithFormat:@"成功：%d",successCount];
    self.percentage.text  = [NSString stringWithFormat:@"%.4f",0.0f];
    NSString *filePath = [[NSBundle mainBundle]pathForResource:@"SC6530_RK4102_release_stone-W1630.02"ofType:@"bin"];
    fileData = [NSData dataWithContentsOfFile:filePath];
    self.fileSize.text = [NSString stringWithFormat:@"%d",(int)(fileData.length)];
    self.version.text = @"1630.02";
    self.btnReboot.enabled = NO;
    self.isAutoMode.on = NO;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(IBAction)onStartUpgrade:(id)sender{
    
    if(self.fileSize.text.length == 0 || self.version.text.length == 0 || self.singlePackageSize.text.length == 0){
        [[[UIAlertView alloc] initWithTitle:@"提示" message:@"请输入参数" delegate:nil cancelButtonTitle:@"确认" otherButtonTitles:nil, nil] show];
        return;
    }
    
    if (isSuccess || wholeStartTime == nil) {
        wholeStartTime = [NSDate date];
    }
    
    
    Firmware *mFirmware = [[Firmware alloc] init];
    mFirmware.version = self.version.text;
    mFirmware.ueSn = [[NSUserDefaults standardUserDefaults] objectForKey:@"SN"];
    mFirmware.singlePackageSize = self.singlePackageSize.text.intValue;
    mFirmware.singleFrameSize = 20;
    mFirmware.isForceUpgradeMode = self.isForceUpgradeMode.isOn;
#ifdef BUILD_FILE_MODEL
    mFirmware.data = mNSData;
#else
    mFirmware.data = fileData;
#endif
    mFirmware.fileSize = mFirmware.data.length;
    mFirmware.md5 = [CocoaSecurity md5WithData:mFirmware.data].hex;
    
    __block NSDate *current = [NSDate date];
    self.time.text = [NSString stringWithFormat:@"用时：%d 秒",0];
    
    if (mRACDisposable) {
        [mRACDisposable dispose];
    }
    
    mRACDisposable = [[RACSignal interval:1 onScheduler:[RACScheduler currentScheduler]] subscribeNext:^(id x) {
        
        self.time.text = [NSString stringWithFormat:@"用时：%d 秒",abs((int)[current timeIntervalSinceNow])] ;
        
    } ];
    self.message.textColor = [UIColor blackColor];
    self.message.text = @"开始升级，请求升级";

    if (upgradeManagerRACDisposable) {
        [upgradeManagerRACDisposable dispose];
    }
    self.btnReboot.enabled = YES;
    upgradeManagerRACDisposable = [[[UpgradeManagerInstance upgradeFirmware:mFirmware] deliverOn:[RACScheduler mainThreadScheduler]]
     subscribeNext:^(UpgradeProgress  *response) {
         
         if (response.runningStatus == UpgradeRunning || response.runningStatus == UpgradeInterrupt ||response.runningStatus == UpgradeDone) {
             
             self.message.textColor = [UIColor blackColor];
             self.percentage.text  = [NSString stringWithFormat:@"%.2f",response.percentage];
             self.remainingTime.text = [NSString stringWithFormat:@"%d小时%d分%d秒",(int)(response.remainingTime/3600.0f),(int)(response.remainingTime%3600/60.0f),(int)(response.remainingTime%3600)%60];
             switch (response.step) {
                 case UpgradeRequestUpgrade:
                 {
                     NSString *tips = @"";
                     switch (response.curRequestUpgradeResponse.result) {
                         case 0:
                             tips = @"不升级";
                             self.message.textColor = [UIColor redColor];
                             break;
                         case 1:
                             tips = @"全新升级";
                             break;
                         case 2:
                             tips = @"继续升级";
                             break;
                             
                         default:
                             break;
                     }
                     self.message.text = [NSString stringWithFormat:@"%@%@",@"收到请求升级响应:",tips];
                     
                     self.isForceUpgradeMode.on = NO;
                 }
                     break;
                 case UpgradeRequestPackage:
                 {
                     NSString *tips1 = @"";
                     NSString *tips2 = @"";
                     switch (response.curRequestPackageResponse.result) {
                         case 0:
                             tips1 = @"错误";
                             self.message.textColor = [UIColor redColor];
                             break;
                         case 1:
                             tips1 = @"正常";
                             break;
                             
                         default:
                             break;
                     }
                     
                     switch (response.curRequestPackageResponse.reason) {
                         case 0:
                             tips2 = @"正常";
                             break;
                         case 1:
                             tips2 = @"CRC错误";
                             
                             break;
                             
                         default:
                             break;
                     }
                     self.message.text = [NSString stringWithFormat:@"%@ index:%d count:%d:%@:%@\n开始发送本包数据..." ,@"收到请求传输包响应",response.curRequestPackageResponse.packageIndex+1,response.curRequestPackageResponse.packageCount,tips1,tips2];
                 }
                     break;
                 case UpgradeSendFrame:
                     
                     break;
                 case UpgradeFinishPackage:
                 {
                     NSString *tips1 = @"";
                     NSString *tips2 = @"";
                     switch (response.curFinishPackageResponse.result) {
                             
                         case 0:
                             tips1 = @"错误";
                             self.message.textColor = [UIColor redColor];
                             break;
                         case 1:
                             tips1 = @"正常";
                             break;
                             
                         default:
                             break;
                     }
                     
                     switch (response.curFinishPackageResponse.reason) {
                         case 0:
                             tips2 = @"无错误";
                             break;
                         case 1:
                             tips2 = @"包CRC错误";
                             break;
                         case 2:
                             tips2 = @"写FLASH错误";
                             break;
                         case 3:
                             tips2 = @"接收数据和包数据不符";
                             break;
                         case 4:
                             tips2 = @"packet id不符";
                             break;
                             
                         default:
                             break;
                     }
                     self.message.text = [NSString stringWithFormat:@"%@ index:%d count:%d:%@:%@" ,@"收到请求传输包响应",response.curFinishPackageResponse.packageIndex+1,response.curFinishPackageResponse.packageCount,tips1,tips2];
                 }
                     break;
                 case UpgradeCheckMD5:
                 {
                     NSString *tips1 = @"";
                     NSString *tips2 = @"";
                     switch (response.curMD5CheckResponse.result) {
                             
                         case 0:
                             tips1 = @"不更新";
                             self.message.textColor = [UIColor redColor];
                             break;
                         case 1:
                             tips1 = @"同意更新";
                             self.message.textColor = [UIColor greenColor];
                             break;
                             
                         default:
                             break;
                     }
                     
                     switch (response.curMD5CheckResponse.reason) {
                         case 0:
                             tips2 = @"无问题";
                             break;
                         case 1:
                             tips2 = @"MD5验证失败";
                             
                             break;
                             
                         default:
                             break;
                     }
                     
                     self.message.text = [NSString stringWithFormat:@"%@%@%@",@"MD5校验结果:",tips1,tips2];
                 }
                     break;
                 case UpgradeReboot:
                     self.message.text = @"重启中";
                     break;
                     
                 default:
                     break;
             }
             
             if (response.runningStatus == UpgradeDone) {
                 successCount++;
                 
                 self.succressCountLab.text = [NSString stringWithFormat:@"成功：%d",successCount];
                 
                 [mRACDisposable dispose];
                 isSuccess = YES;
                 self.isForceUpgradeMode.on = YES;
                 
                 if (self.isAutoMode.on) {
                     [self onStartUpgrade:nil];
                 }
                self.btnReboot.enabled = YES;

             } else if(response.runningStatus == UpgradeInterrupt){
                [mRACDisposable dispose];
             }

         } else if(response.runningStatus == UpgradeError){
             
             NSError *error = response.error;
             
             errorCount++;
             
             self.message.textColor = [UIColor redColor];
             self.message.text = [error localizedDescription];
             
             [mRACDisposable dispose];

             isSuccess = NO;
         }
         
         
     }];
    
}

-(void)viewWillDisappear:(BOOL)animated{
    [super viewWillDisappear:animated];
    [upgradeManagerRACDisposable dispose];
    [mRACDisposable dispose];
    [playSound dispose];
}

-(void) registerSound

{
    NSString *path = [[NSBundle mainBundle] pathForResource:@"sound" ofType:@"caf"];
    if (path) {
        //注册声音到系统
        AudioServicesCreateSystemSoundID((__bridge CFURLRef)[NSURL fileURLWithPath:path],&shake_sound_male_id);
    }
}

-(IBAction)finish:(id)sender{

    [UpgradeManagerInstance cancelUpgrade];
    
}

-(IBAction)reboot:(id)sender{
    
    [[RK4103APIServiceImpl reboot:@"B00G3PC1Q4"] subscribeNext:^(id response){
    
    } error:^(NSError *error){
    
    }];
    
}

/*
 #pragma mark - Navigation
 
 // In a storyboard-based application, you will often want to do a little preparation before navigation
 - (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
 // Get the new view controller using [segue destinationViewController].
 // Pass the selected object to the new view controller.
 }
 */

-(void)dealloc{
    NSLog(@"UpgradeViewController:dealloc");
}

@end
