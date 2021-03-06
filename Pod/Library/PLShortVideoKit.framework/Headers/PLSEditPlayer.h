//
//  PLSEditPlayer.h
//  PLShortVideoKit
//
//  Created by suntongmian on 2017/7/10.
//  Copyright © 2017年 Pili Engineering, Qiniu Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <CoreVideo/CoreVideo.h>
#import "PLSTypeDefines.h"

@class PLSEditPlayer;

@protocol PLSEditPlayerDelegate <NSObject>

@optional

/**
 @brief 视频数据回调, pixelBuffer 类型为 kCVPixelFormatType_32BGRA

 @return 返回 kCVPixelFormatType_32BGRA 类型的 CVPixelBufferRef

 @since      v1.1.0
 */
- (CVPixelBufferRef __nonnull)player:(PLSEditPlayer *__nonnull)player didGetOriginPixelBuffer:(CVPixelBufferRef __nonnull)pixelBuffer;

@end


@interface PLSEditPlayer : AVPlayer

/**
 @brief delegate
 
 @since      v1.1.0
 */
@property (weak, nonatomic) __nullable id<PLSEditPlayerDelegate> delegate;

/**
 @brief 循环播放。设置为 YE，表示单曲循环。默认为 NO
 
 @since      v1.1.0
 */
@property (assign, nonatomic) BOOL loopEnabled;

/**
 @brief 播放器是否在播放状态
 
 @since      v1.1.0
 */
@property (readonly, nonatomic) BOOL isPlaying;

/**
 @brief 播放器的预览视图
 
 @since      v1.1.0
 */
@property (assign, nonatomic) UIView *__nullable preview;

/**
 @brief 播放器预览视图的填充方式
 
 @since      v1.1.0
 */
@property (assign, nonatomic) PLSVideoFillModeType fillMode;

/**
 @brief 播放器的音量
 
 @since      v1.1.0
 */
@property (assign, nonatomic) float volume;

/**
 @brief 播放器播放文件的 timeRange 范围内 [start, duration] 片段
 
 @since      v1.1.0
 */
@property (assign, nonatomic) CMTimeRange timeRange;

/**
 @brief 通过 stringPath 加载 AVPlayerItem
 
 @since      v1.1.0
 */
- (void)setItemByStringPath:(NSString *__nullable)stringPath;

/**
 @brief 通过 url 加载 AVPlayerItem
 
 @since      v1.1.0
 */
- (void)setItemByUrl:(NSURL *__nullable)url;

/**
 @brief 通过 asset 加载 AVPlayerItem
 
 @since      v1.1.0
 */
- (void)setItemByAsset:(AVAsset *__nullable)asset;

/**
 @brief 接收 item 去播放
 
 @since      v1.1.0
 */
- (void)setItem:(AVPlayerItem *__nullable)item;

/**
 @brief 播放
 
 @since      v1.1.0
 */
- (void)play;

/**
 @brief 暂停
 
 @since      v1.1.0
 */
- (void)pause;

/**
 *  开启水印
 *
 *  @param waterMarkImage 水印的图片
 *  @param position       水印的位置
 
 @since      v1.1.0
 */
-(void)setWaterMarkWithImage:(UIImage *__nonnull)waterMarkImage position:(CGPoint)position;

/**
 *  移除水印
 
 @since      v1.1.0
 */
-(void)clearWaterMark;

@end
