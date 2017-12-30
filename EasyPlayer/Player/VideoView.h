
#import <UIKit/UIKit.h>
#import "RtspDataReader.h"

typedef enum {
    Stopped,    // 停止
    Suspend,    // 暂停
    Connecting, // 连接中
    Rendering,  // 播放中
}IVideoStatus;

@protocol VideoViewDelegate;

@interface VideoView : UIView<UIGestureRecognizerDelegate>

@property (nonatomic, weak) UIView *container;
@property (nonatomic, strong) UIButton *addButton;

@property (nonatomic, weak) id<VideoViewDelegate> delegate;

@property (nonatomic, copy) NSString *url;              // 播放地址
@property (nonatomic, copy) NSString *recordFilePath;   // 录像地址
@property (nonatomic, copy) NSString *screenShotPath;   // 截图地址

@property (nonatomic, strong) RtspDataReader *reader;
@property (nonatomic, assign) IVideoStatus videoStatus;

@property (nonatomic, assign) BOOL active;
@property (nonatomic, assign) BOOL useHWDecoder;        // 是否启用硬解
@property (nonatomic, assign) BOOL audioPlaying;        // 自动播放音频
@property (nonatomic, assign) BOOL showAllRegon;        //
@property (nonatomic, assign) BOOL fullScreen;          // 是否全屏
@property (nonatomic, assign) BOOL showActiveStatus;    //

@property (nonatomic, assign) int screenShotCount;      // 截屏


- (void)beginTransform;
- (void)endTransform;

// ----------------- 播放控制 -----------------
- (void)stopAudio;
- (void)startPlay;
- (void)stopPlay;
- (void)flush;

@end

@protocol VideoViewDelegate <NSObject>

@optional
- (void)videoViewDidiUpdateStream:(VideoView *)view;
- (void)videoViewBeginActive:(VideoView *)view;

- (void)videoViewWillAnimateToFullScreen:(VideoView *)view;
- (void)videoViewWillAnimateToNomarl:(VideoView *)view;

- (void)videoViewWillTryToConnect:(VideoView *)view;

@end
