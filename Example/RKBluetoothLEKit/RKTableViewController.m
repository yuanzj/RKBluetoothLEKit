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
#import <RKBluetoothLE_iOS/YadeaParamter.h>


@interface RKTableViewController (){

    NSArray *dataSrc;
    
    NSString *ueSN;
    NSString *macAddress;
    
}

@end

@implementation RKTableViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
    
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
    NSUserDefaults *user = [NSUserDefaults standardUserDefaults];
    ueSN = [user objectForKey:@"SN"];
    macAddress = [user objectForKey:@"MAC"];
    
    dataSrc = @[@"上电",@"断电",@"寻车",@"车辆状态",@"故障检测",@"个性化配置",@"来电、短信仪表显示",@"获取个性化参数",@"固件升级",@"读取版本号"];


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
        case 7:
            [self getCustomParamter];
            break;
        case 8:
            [self update];
            break;
        case 9:
            [self readVersion];
            break;
        default:
            break;
    }
}

-(void)powerOff{
    
    [[YadeaApiServiceImpl powerOff:ueSN] subscribeNext:^(RemoteControlResult *response){
    
    } error:^(NSError *error){
        
    }];
    
}

-(void)powerOn{
    
    [[YadeaApiServiceImpl powerOn:ueSN] subscribeNext:^(RemoteControlResult *response){
        
    } error:^(NSError *error){
        
    }];
    
}


-(void)find{
    
    [[YadeaApiServiceImpl find:ueSN] subscribeNext:^(RemoteControlResult *response){
        
    } error:^(NSError *error){
        NSLog(@"%@",error);
    }];
    
}

-(void)getVehicleStatus{
    
    [[[YadeaApiServiceImpl getVehicleStatus:ueSN] deliverOn:[RACScheduler mainThreadScheduler]] subscribeNext:^(VehicleStatus *response){
        [[[UIAlertView alloc] initWithTitle:nil message:[response description] delegate:nil cancelButtonTitle:@"确认" otherButtonTitles:nil, nil] show];
    } error:^(NSError *error){
        
    }];
    
}

-(void)getFault{
    
    [[[YadeaApiServiceImpl getFault:ueSN] deliverOn:[RACScheduler mainThreadScheduler]]  subscribeNext:^(YadeaFault *response){
        [[[UIAlertView alloc] initWithTitle:nil message:[response description] delegate:nil cancelButtonTitle:@"确认" otherButtonTitles:nil, nil] show];
    } error:^(NSError *error){
        
    }];
    
}

-(void)getCustomParamter{
    
    [[[YadeaApiServiceImpl getCustomParameter:ueSN ]deliverOn:[RACScheduler mainThreadScheduler]] subscribeNext:^(YadeaParamter *response){
        NSLog(@"%@",[response description]);
        
        [[[UIAlertView alloc] initWithTitle:nil message:[response description] delegate:nil cancelButtonTitle:@"确认" otherButtonTitles:nil, nil] show];
        
    } error:^(NSError *error){
        
    }];
    
}

-(void)setCustomParamter{
    YadeaParamter *mYadeaParamter       = [[YadeaParamter alloc] init];
    mYadeaParamter.colorfulLight = 0x0000ff;
    mYadeaParamter.autoCloseLight = 30;
    mYadeaParamter.startTime = @"17:00";
    mYadeaParamter.endTime = @"20:00";
    mYadeaParamter.gears = 1;
    [[[YadeaApiServiceImpl setCustomParameter:ueSN parameter :mYadeaParamter] deliverOn:[RACScheduler mainThreadScheduler]] subscribeNext:^(ConfigResult *response){
        
        [[[UIAlertView alloc] initWithTitle:nil message:[NSString stringWithFormat:@"success:%d",response.success] delegate:nil cancelButtonTitle:@"确认" otherButtonTitles:nil, nil] show];
    } error:^(NSError *error){
        
        [[[UIAlertView alloc] initWithTitle:nil message:[NSString stringWithFormat:@"error:%@",[error localizedDescription]] delegate:nil cancelButtonTitle:@"确认" otherButtonTitles:nil, nil] show];
    }];
    
}

-(void)setInstrument{
    
    Instrument *mInstrument = [[Instrument alloc] init];
    mInstrument.telephone   = 1;
    mInstrument.SMS         = 1;
    
    [[YadeaApiServiceImpl setInstrument:ueSN parameter :mInstrument] subscribeNext:^(ConfigResult *response){
        
    } error:^(NSError *error){
        
    }];
    
}


-(void)update{
    [self performSegueWithIdentifier:@"update" sender:self];
}

-(void)readVersion{
    [[[RK4102APIServiceImpl getDeviceVersion:ueSN paramter:VERSION_TYPE_ECU]deliverOn:[RACScheduler mainThreadScheduler]] subscribeNext:^(YadeaParamter *response){
        NSLog(@"%@",[response description]);
        
        [[[UIAlertView alloc] initWithTitle:nil message:[response description] delegate:nil cancelButtonTitle:@"确认" otherButtonTitles:nil, nil] show];
        
    } error:^(NSError *error){
        NSLog(@"%@",error);
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
