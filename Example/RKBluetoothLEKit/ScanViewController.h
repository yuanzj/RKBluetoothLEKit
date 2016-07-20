//
//  ScanViewController.h
//  车精灵
//
//  Created by apple on 15/5/26.
//  Copyright (c) 2015年 无锡锐祺. All rights reserved.
//

#import <UIKit/UIKit.h>
@import AVFoundation;

@protocol ScanViewControllerDelegate <NSObject>

-(void)scanReult:(NSString*)value;

@end
@interface ScanViewController : UIViewController

@property(nonatomic,weak)id<ScanViewControllerDelegate> delegate;

@end
