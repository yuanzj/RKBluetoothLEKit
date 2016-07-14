//
//  RKAppDelegate.m
//  RKBluetoothLEKit
//
//  Created by yuanzhijian on 05/07/2016.
//  Copyright (c) 2016 yuanzhijian. All rights reserved.
//

#import "RKAppDelegate.h"
#import <CocoaSecurity/CocoaSecurity.h>
#import <RKBluetoothLE_iOS/BleLog.h>

@interface RKAppDelegate (){
    
    RACDisposable *authResultSignalDisposable;
    RACDisposable *connectionDisposable;
}

@end
@implementation RKAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // Override point for customization after application launch.
    self.mRkBluetoothClient = [RkBluetoothClient shareClient];
    [self.mRkBluetoothClient setMaxTaskCount:3];
    self.mRk4102ApiService = [self.mRkBluetoothClient createRk4102ApiService];
    
    //获取连接状态、蓝牙设备状态
    connectionDisposable = [[[self.mRkBluetoothClient observeConnectionStateChanges]  deliverOn:[RACScheduler mainThreadScheduler]]
                            subscribeNext:^(NSNotification *response) {
                                
                                if(response.userInfo){
                                    
                                    //设备状态
                                    switch ([(NSNumber*)response.userInfo[CentralManagerStateKey] integerValue]) {
                                        case CBCentralManagerStateUnknown:
                                            
                                            break;
                                        case CBCentralManagerStateResetting:
                                            
                                            break;
                                        case CBCentralManagerStateUnsupported:
                                            NSLog(@"当前设备不支持蓝牙");
                                            break;
                                        case CBCentralManagerStateUnauthorized:
                                            
                                            break;
                                        case CBCentralManagerStatePoweredOff:
                                            NSLog(@"蓝牙被关闭了");
                                            break;
                                        case CBCentralManagerStatePoweredOn:
                                            NSLog(@"蓝牙打开了");
                                            break;
                                            
                                        default:
                                            break;
                                    }
                                    
                                    //连接状态
                                    switch ([(NSNumber*)response.userInfo[ConnectStateKey] integerValue]) {

                                        case RKBLEStateDefault:
                                            
                                            break;
                                        case RKBLEStateStart:
                                            
                                            break;
                                        case RKBLEStateScanning:
                                            
                                            break;
                                        case RKBLEStateConnecting:
                                            
                                            break;
                                        case RKBLEStateConnected:
                                            
                                            break;
                                        case RKBLEStateDisconnect:
                                            
                                            break;
                                        case RKBLEStateFailure:
                                            
                                            break;
                                        default:
                                            break;
                                    }
                                    
                                }
                            }];
    authResultSignalDisposable = [[[self.mRk4102ApiService authResultSignal] deliverOn:[RACScheduler mainThreadScheduler]]
                                  subscribeNext:^(NSNotification *response) {
                                      //鉴权成功
                                      if(response.userInfo[RKBLEAuthResultStatus]){
                                          NSLog(@"鉴权成功");
                                          //更新本地标志位，标示下一次鉴权使用FF鉴权
                                          
                                      } else {
                                          //鉴权失败
                                          NSLog(@"鉴权失败");
                                          //更新本地标志位，标示下一次鉴权使用鉴权码鉴权
                                          
                                      }
                                  }];
    
    self.mYadeaApiService = [[YadeaApiService alloc] initWithRk4102ApiService:self.mRk4102ApiService];
    
    //鉴权码注入方法，每次连接车辆的时候block里面的内容会自动回调
    [self.mYadeaApiService setPostAuthCodeBlock:^(NSString *peripheralName){
        //在这里获取本地存储的当前车辆鉴权码
        NSString *authCode = @"546e1271ab34bce4943941cd1be7430092eb82f37963d5f012d6ed68fcf80c0e9e04f69c18c5160752fa60a8f737cb1b2fb8087b0388073fdfa61753afe6c0f3";
        if (authCode.length > 0) {
            return authCode;
        } else {
            return @"/////////////////////w==";
        }
    }];
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
