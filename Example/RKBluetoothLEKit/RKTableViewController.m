//
//  RKTableViewController.m
//  RKBluetoothLEKit
//
//  Created by apple on 16/5/7.
//  Copyright © 2016年 yuanzhijian. All rights reserved.
//

#import "RKTableViewController.h"
#import "RKAppDelegate.h"
#import "CocoaSecurity.h"
#import <RKBluetoothLE_iOS/CustomParameter.h>


@interface RKTableViewController (){

    NSArray *dataSrc;
    
}

@end

@implementation RKTableViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
    
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
    
    dataSrc = @[@"上电",@"断电",@"寻车",@"车辆状态",@"故障检测",@"个性化配置",@"来电、短信仪表显示"];
    
    [RK4102APIServiceImpl setPostAuthCodeBlock:^(NSString *peripheralName){
        CocoaSecurityDecoder *mCocoaSecurityDecoder = [[CocoaSecurityDecoder alloc] init];
        return [mCocoaSecurityDecoder base64:@"Q1NsmKbbaf+mfktSpyNJ5w=="];
    }];

}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return dataSrc.count;
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"testItem" forIndexPath:indexPath];
    
    // Configure the cell...
    cell.textLabel.text = dataSrc[indexPath.row];
    return cell;
}


/*
// Override to support conditional editing of the table view.
- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath {
    // Return NO if you do not want the specified item to be editable.
    return YES;
}
*/

/*
// Override to support editing the table view.
- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath {
    if (editingStyle == UITableViewCellEditingStyleDelete) {
        // Delete the row from the data source
        [tableView deleteRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationFade];
    } else if (editingStyle == UITableViewCellEditingStyleInsert) {
        // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view
    }   
}
*/

/*
// Override to support rearranging the table view.
- (void)tableView:(UITableView *)tableView moveRowAtIndexPath:(NSIndexPath *)fromIndexPath toIndexPath:(NSIndexPath *)toIndexPath {
}
*/

/*
// Override to support conditional rearranging of the table view.
- (BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath {
    // Return NO if you do not want the item to be re-orderable.
    return YES;
}
*/

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    
    switch (indexPath.row) {
        case 0:
            [self powerOn];
            break;
        case 1:
            [self powerOff];
            break;
        case 2:
            [self find];
            break;
        case 3:
            [self getVehicleStatus];
            break;
        case 4:
            [self getFault];
            break;
        case 5:
            [self setCustomParamter];
            break;
        case 6:
            [self setInstrument];
            break;
            
            
        default:
            break;
    }
}

-(void)powerOff{
    
    [[YadeaApiServiceImpl powerOff:@"B00G10B6F3"] subscribeNext:^(RemoteControlResult *response){
    
    } error:^(NSError *error){
        
    }];
    
}

-(void)powerOn{
    
    [[YadeaApiServiceImpl powerOn:@"B00G10B6F3"] subscribeNext:^(RemoteControlResult *response){
        
    } error:^(NSError *error){
        
    }];
    
}


-(void)find{
    
    [[YadeaApiServiceImpl find:@"B00G10B6F3"] subscribeNext:^(RemoteControlResult *response){
        
    } error:^(NSError *error){
        
    }];
    
}

-(void)getVehicleStatus{
    
    [[YadeaApiServiceImpl getVehicleStatus:@"B00G10B6F3"] subscribeNext:^(VehicleStatus *response){
        
    } error:^(NSError *error){
        
    }];
    
}

-(void)getFault{
    
    [[YadeaApiServiceImpl getFault:@"B00G10B6F3"] subscribeNext:^(YadeaFault *response){
        
    } error:^(NSError *error){
        
    }];
    
}

-(void)setCustomParamter{
    CustomParameter *mECUParameter       = [[CustomParameter alloc] init];
    mECUParameter.alarmType              = 0;
    mECUParameter.autoSafety             = 2;
    mECUParameter.autoHold               = 2;
    mECUParameter.hornVolume             = 1;
    mECUParameter.colorfulLight          = 0xffffff;
    mECUParameter.autoCloseLight         = 0;
    
    mECUParameter.onTimeOpenLightStartHH = 8;
    mECUParameter.onTimeOpenLightStartMM = 0;
    mECUParameter.onTimeOpenLightEndHH   = 10;
    mECUParameter.onTimeOpenLightEndMM   = 0;

    
    [[YadeaApiServiceImpl setCustomParameter:@"B00G10B6F3" parameter :mECUParameter] subscribeNext:^(ConfigResult *response){
        
    } error:^(NSError *error){
        
    }];
    
}

-(void)setInstrument{
    
    Instrument *mInstrument = [[Instrument alloc] init];
    mInstrument.telephone   = 1;
    mInstrument.SMS         = 1;
    
    [[YadeaApiServiceImpl setInstrument:@"B00G10B6F3" parameter :mInstrument] subscribeNext:^(ConfigResult *response){
        
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

@end
