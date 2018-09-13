//
//  RkBluetoothClient.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/5/3.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BLEStack.h"
#import "Rk4102ApiService.h"
#import "Rk4103ApiService.h"
#import "RK44xxApiService.h"

@interface RkBluetoothClient : NSObject
/**
 *  必须使用单例创建对象
 *
 *  @return
 */
+(instancetype)shareClient;

/**
 *  设置列队上限
 *
 *  @param maxQueueCount 
 */
-(void)setMaxTaskCount:(int) maxQueueCount;

/**
 *  获取连接状态
 *
 *  @return
 */
-(RACSignal*)observeConnectionStateChanges;

/**
 *  取消所有的队列内请求
 */
-(void)cancelAll;

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
 *  获取RK4102APIService
 *
 *  @return 
 */
-(Rk4102ApiService*)createRk4102ApiService;

/**
 *  获取RK4103APIService
 *
 *  @return
 */
-(Rk4103ApiService*)createRk4103ApiService;

/**
 *  获取RK44xxAPIService
 *
 *  @return
 */
-(RK44xxApiService*)createRk44xxApiService;

@end
