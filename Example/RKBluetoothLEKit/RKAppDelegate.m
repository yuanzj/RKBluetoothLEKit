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

//    M8Cjz3SFrA3R0LAzBB9xGA==
//
//    B00GDV5DZ3


//B00G10B6F3 C0:27:15:09:A7:E6 Q1NsmKbbaf+mfktSpyNJ5w==
//
@interface RKAppDelegate (){
    
    RACDisposable *connectionDisposable;
}

@end
@implementation RKAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // Override point for customization after application launch.
    self.mRkBluetoothClient = [RkBluetoothClient shareClient];
    [self.mRkBluetoothClient setMaxTaskCount:3];
    self.mRk4103ApiService = [self.mRkBluetoothClient createRk4103ApiService];
    
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
   
    //鉴权码注入方法，每次连接车辆的时候block里面的内容会自动回调
    [self.mRk4103ApiService setPostAuthCodeBlock:^(NSString *peripheralName , ProvideAuthCodeBlock postAuthCode){
        //在这里从服务器获取当前车辆的鉴权码
        NSString *authCode = @"";
        if (authCode.length > 0) {
            postAuthCode(authCode,nil);
        } else {
            postAuthCode(@"/////////////////////w==",nil);
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
