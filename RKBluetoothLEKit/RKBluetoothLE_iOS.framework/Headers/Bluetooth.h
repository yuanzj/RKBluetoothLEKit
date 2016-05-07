//
//  Bluetooth.h
//  RokyinfoBLEDemo
//
//  Created by 袁志健 on 16/3/29.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ReactiveCocoa/ReactiveCocoa.h>
#import "BLERequest.h"



@protocol Bluetooth <NSObject>

/**
 *  执行请求
 *
 *  @param request
 *
 *  @return
 */
- (RACSignal*) performRequest:(BLERequest*) request;



/**
 *  结束请求
 */
- (void)finish:(BLERequest*) request;


@end
