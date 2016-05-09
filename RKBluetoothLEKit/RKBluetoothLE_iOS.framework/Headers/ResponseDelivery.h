//
//  ResponseDelivery.h
//  RokyinfoBLEDemo
//
//  Created by 袁志健 on 16/3/29.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BLERequest.h"
#import "Runnable.h"

@protocol ResponseDelivery <NSObject>

/**
 * Parses a response from the ble and delivers it.
 */
-(void)postResponse:(BLERequest*) request response:(Response*) response;

/**
 * Parses a response from the ble and delivers it. The provided
 * Runnable will be executed after delivery.
 */
-(void)postResponse:(BLERequest*) request response:(Response*) response runnable:(id<Runnable>) runnable;

/**
 * Posts an error for the given request.
 */
-(void)postError:(BLERequest*) request error:(NSError*) error;

@end
