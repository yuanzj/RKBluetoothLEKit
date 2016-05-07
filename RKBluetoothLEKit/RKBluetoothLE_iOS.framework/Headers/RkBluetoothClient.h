//
//  RkBluetoothClient.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/5/3.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BLEStack.h"
#import "RK410APIService.h"

@interface RkBluetoothClient : NSObject
/**
 *  必须使用单例创建对象
 *
 *  @return
 */
+(instancetype)shareClient;

/**
 *  获取连接状态
 *
 *  @return
 */
-(RACSignal*)observeConnectionStateChanges;

/**
 *  断开连接
 */
-(void)disconnect;

/**
 *  扫描设备
 *
 *  @param mScanFilter 设备过滤器
 *
 *  @return
 */
-(RACSignal*)scanBleDevices:(ScanFilter) mScanFilter;

/**
 *  获取RK410APIService
 *
 *  @return 
 */
-(RK410APIService*)createRk410ApiService;

@end
