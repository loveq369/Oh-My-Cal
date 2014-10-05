///:
/*****************************************************************************
 **                                                                         **
 **                               .======.                                  **
 **                               | INRI |                                  **
 **                               |      |                                  **
 **                               |      |                                  **
 **                      .========'      '========.                         **
 **                      |   _      xxxx      _   |                         **
 **                      |  /_;-.__ / _\  _.-;_\  |                         **
 **                      |     `-._`'`_/'`.-'     |                         **
 **                      '========.`\   /`========'                         **
 **                               | |  / |                                  **
 **                               |/-.(  |                                  **
 **                               |\_._\ |                                  **
 **                               | \ \`;|                                  **
 **                               |  > |/|                                  **
 **                               | / // |                                  **
 **                               | |//  |                                  **
 **                               | \(\  |                                  **
 **                               |  ``  |                                  **
 **                               |      |                                  **
 **                               |      |                                  **
 **                               |      |                                  **
 **                               |      |                                  **
 **                   \\    _  _\\| \//  |//_   _ \// _                     **
 **                  ^ `^`^ ^`` `^ ^` ``^^`  `^^` `^ `^                     **
 **                                                                         **
 **                       Copyright (c) 2014 Tong G.                        **
 **                          ALL RIGHTS RESERVED.                           **
 **                                                                         **
 ****************************************************************************/

#import <Cocoa/Cocoa.h>

typedef NS_ENUM( short, OMCOpenMode ) { OMCHangInMenuMode, OMCGlobalCalloutMode };

@class OMFStatusItemView;
@class OMFMainPanelController;
@class OMFDashboardView;
@class OMFAboutPanelController;

@class OMFPanelBackgroundView;

// OMFMainPanelControllerDelegate protocol
@protocol OMFMainPanelControllerDelegate <NSObject>

@required
- ( OMFStatusItemView* ) statusItemViewForPanelController: ( OMFMainPanelController* )_PanelController;

@end // OMFMainPanelControllerDelegate

// OMFMainPanelController class
@interface OMFMainPanelController : NSWindowController <NSWindowDelegate>
    {
@private
    id <OMFMainPanelControllerDelegate> _delegate;

    OMFPanelBackgroundView* _backgroundView;
    OMFDashboardView*       _dashboardView;

    BOOL _hasOpened;
    OMCOpenMode _currentOpenMode;
    }

@property ( nonatomic, retain ) id <OMFMainPanelControllerDelegate> delegate;

@property ( nonatomic, unsafe_unretained ) IBOutlet OMFPanelBackgroundView* backgrondView;
@property ( nonatomic, retain ) OMFAboutPanelController* aboutPanelController;

@property ( nonatomic, unsafe_unretained ) IBOutlet NSMenuItem* _startAtLoginMenuItem; // Not successful, lost to Sandbox😩
@property ( nonatomic, unsafe_unretained ) IBOutlet NSMenuItem* _calloutByKeyCombinationMenuItem;

@property ( nonatomic, assign, setter = setOpened: ) BOOL hasOpened;
@property ( nonatomic, assign ) OMCOpenMode currentOpenMode;

+ ( id ) mainPanelControllerWithDelegate: ( id <OMFMainPanelControllerDelegate> )_Delegate;
- ( id ) initWithDelegate: ( id <OMFMainPanelControllerDelegate> )_Delegate;

- ( NSRect ) frameBasedOnFrameOfStatusItemView: ( NSRect )_Frame;
- ( NSRect ) frameCenteredInScreen: ( NSRect )_Frame;

#pragma mark Panel Handling
- ( void ) openPanelWithMode: ( OMCOpenMode )_OpenMode;
- ( void ) closePanel;

- ( void ) _fuckPanel: ( BOOL )_IsHighlighting;

#pragma mark IBActions
- ( IBAction ) about: ( id )_Sender;

@end // OMFMainPanelController

/////////////////////////////////////////////////////////////////////////////

/****************************************************************************
 **                                                                        **
 **      _________                                      _______            **
 **     |___   ___|                                   / ______ \           **
 **         | |     _______   _______   _______      | /      |_|          **
 **         | |    ||     || ||     || ||     ||     | |    _ __           **
 **         | |    ||     || ||     || ||     ||     | |   |__  \          **
 **         | |    ||     || ||     || ||     ||     | \_ _ __| |  _       **
 **         |_|    ||_____|| ||     || ||_____||      \________/  |_|      **
 **                                           ||                           **
 **                                    ||_____||                           **
 **                                                                        **
 ***************************************************************************/
///:~