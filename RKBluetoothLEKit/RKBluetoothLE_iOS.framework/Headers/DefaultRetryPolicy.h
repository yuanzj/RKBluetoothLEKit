//
//  DefaultRetryPolicy.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/4/8.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RetryPolicy.h"

@interface DefaultRetryPolicy : NSObject<RetryPolicy>

-(id)init;

-(id)initWithTimeout:(float)timeout delayTime:(float)delayTime maxRetries:(int)maxRetries;

@end
