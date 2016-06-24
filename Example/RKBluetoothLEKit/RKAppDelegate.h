//
//  RKAppDelegate.h
//  RKBluetoothLEKit
//
//  Created by yuanzhijian on 05/07/2016.
//  Copyright (c) 2016 yuanzhijian. All rights reserved.
//

@import UIKit;

#import <RKBluetoothLE_iOS/RkBluetoothClient.h>
#import <RKBluetoothLE_iOS/YadeaApiService.h>

#define RK4102APIServiceImpl ((RKAppDelegate*)[[UIApplication sharedApplication] delegate]).mRk4102ApiService

#define YadeaApiServiceImpl ((RKAppDelegate*)[[UIApplication sharedApplication]  delegate]).mYadeaApiService

@interface RKAppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow          *window;

@property (strong, nonatomic) RkBluetoothClient *mRkBluetoothClient;

@property (strong, nonatomic) Rk4102ApiService  *mRk4102ApiService;

@property (strong, nonatomic) YadeaApiService   *mYadeaApiService;

@end
