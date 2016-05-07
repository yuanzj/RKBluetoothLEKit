//
//  RKAppDelegate.h
//  RKBluetoothLEKit
//
//  Created by yuanzhijian on 05/07/2016.
//  Copyright (c) 2016 yuanzhijian. All rights reserved.
//

@import UIKit;

#import <RKBluetoothLE_iOS/RkBluetoothClient.h>
#import <RKBluetoothLE_iOS/RK410APIService.h>

#define RK410APIServiceImpl ((RKAppDelegate*)[[UIApplication sharedApplication] delegate]).mRK410APIService

@interface RKAppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow          *window;

@property (strong, nonatomic) RkBluetoothClient *mRkBluetoothClient;

@property (strong, nonatomic) RK410APIService   *mRK410APIService;

@end
