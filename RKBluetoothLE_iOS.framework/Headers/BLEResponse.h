//
//  BLEResponse.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/3/30.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Response.h"

@interface BLEResponse : NSObject

@property (nonatomic,strong) NSData         *data;

@property (nonatomic,assign) NSTimeInterval bleTimeMs;


@end
