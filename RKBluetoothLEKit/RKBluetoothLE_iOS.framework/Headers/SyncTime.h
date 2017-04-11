//
//  SyncTime.h
//  Pods
//
//  Created by caoyy on 17/4/10.
//
//

#import <Foundation/Foundation.h>
#import "BaseParameter.h"

@interface SyncTime : BaseParameter

@property (nonatomic,assign) Byte     hour;

@property (nonatomic,assign) Byte     minute;

@property (nonatomic,assign) Byte     second;

@end
