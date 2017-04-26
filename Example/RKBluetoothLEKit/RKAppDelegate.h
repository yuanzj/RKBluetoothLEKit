//
//  RKAppDelegate.h
//  RKBluetoothLEKit
//
//  Created by yuanzhijian on 05/07/2016.
//  Copyright (c) 2016 yuanzhijian. All rights reserved.
//

@import UIKit;

#import <RKBluetoothLE_iOS/RkBluetoothClient.h>
#import <RKBluetoothLE_iOS/UpgradeManager.h>

#define RK4103APIServiceImpl ((RKAppDelegate*)[[UIApplication sharedApplication] delegate]).mRk4103ApiService

#define UpgradeManagerInstance ((RKAppDelegate*)[[UIApplication sharedApplication] delegate]).mUpgradeManager

@interface RKAppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow          *window;

@property (strong, nonatomic) RkBluetoothClient *mRkBluetoothClient;
//蓝牙接口（第三方请关注此接口的相关方法）
@property (strong, nonatomic) Rk4103ApiService  *mRk4103ApiService;
//蓝牙固件升级
@property (strong, nonatomic) UpgradeManager    *mUpgradeManager;

@end
