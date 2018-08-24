#import <Foundation/Foundation.h>

#import "MGLFoundation.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Constants indicating the message's logging level.
 */
typedef NS_ENUM(NSInteger, MGLLoggingLevel) {
    /**
     None-level messages are ignored.
     */
    MGLLoggingLevelNone = 0,
    /**
     Info-level messages contain information that may be helpful for flow tracing
     but is not essential.
     */
    MGLLoggingLevelInfo,
    /**
     Debug-level messages contain information that may be helpul for troubleshooting
     specific problems.
     */
    MGLLoggingLevelDebug,
    /**
     Error-level messages contain information that is intended to aid in process-level
     errors.
     */
    MGLLoggingLevelError,
    /**
     Fault-level messages contain system-level error information.
     */
    MGLLoggingLevelFault,
    /**
     :nodoc: Any new logging level should be included in the default logging implementation.
     */
};

typedef void (^MGLLoggingBlockHandler)(MGLLoggingLevel, NSString *, NSString *);

MGL_EXPORT

/**
 `MGLLogging` implements a singleton (shared object) that manages message logging.
 */
@interface MGLLogging : NSObject

/**
 The handler this SDK uses to log messages.
 
 If this property is set to nil or if no custom handler is provided this property
 is set to the default handler.
 
 The default handler uses `os_log` and `NSLog` for iOS 10 + and iOS < 10 respectively.
 */
@property (nonatomic, assign, null_resettable) MGLLoggingBlockHandler handler;

/**
 The logging level.
 
 The default value is `MGLLoggingLevelNone`.
 
 Setting this property includes logging levels less than or equal to the setted value.
 */
@property (assign, nonatomic) MGLLoggingLevel loggingLevel;

/**
 Returns the shared logging object.
 */
@property (class, nonatomic, readonly) MGLLogging *sharedInstance;

- (MGLLoggingBlockHandler)handler UNAVAILABLE_ATTRIBUTE;

@end

NS_ASSUME_NONNULL_END
