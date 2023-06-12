#import <Foundation/Foundation.h>
#import "OAICreateInboxForwarderOptions.h"
#import "OAIInboxForwarderDto.h"
#import "OAIInboxForwarderTestOptions.h"
#import "OAIInboxForwarderTestResult.h"
#import "OAIPageInboxForwarderDto.h"
#import "OAIPageInboxForwarderEvents.h"
#import "OAITestNewInboxForwarderOptions.h"
#import "OAIApi.h"

/**
* MailSlurp API
* MailSlurp is an API for sending and receiving emails from dynamically allocated email addresses. It's designed for developers and QA teams to test applications, process inbound emails, send templated notifications, attachments, and more.  ## Resources  - [Homepage](https://www.mailslurp.com) - Get an [API KEY](https://app.mailslurp.com/sign-up/) - Generated [SDK Clients](https://docs.mailslurp.com/) - [Examples](https://github.com/mailslurp/examples) repository
*
* The version of the OpenAPI document: 6.5.2
* Contact: contact@mailslurp.dev
*
* NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
* https://openapi-generator.tech
* Do not edit the class manually.
*/



@interface OAIInboxForwarderControllerApi: NSObject <OAIApi>

extern NSString* kOAIInboxForwarderControllerApiErrorDomain;
extern NSInteger kOAIInboxForwarderControllerApiMissingParamErrorCode;

-(instancetype) initWithApiClient:(OAIApiClient *)apiClient NS_DESIGNATED_INITIALIZER;

/// Create an inbox forwarder
/// Create a new inbox rule for forwarding, blocking, and allowing emails when sending and receiving
///
/// @param inboxId Inbox id to attach forwarder to
/// @param createInboxForwarderOptions 
/// 
///  code:200 message:"OK"
///
/// @return OAIInboxForwarderDto*
-(NSURLSessionTask*) createNewInboxForwarderWithInboxId: (NSString*) inboxId
    createInboxForwarderOptions: (OAICreateInboxForwarderOptions*) createInboxForwarderOptions
    completionHandler: (void (^)(OAIInboxForwarderDto* output, NSError* error)) handler;


/// Delete an inbox forwarder
/// Delete inbox forwarder
///
/// @param _id ID of inbox forwarder
/// 
///  code:204 message:"No Content"
///
/// @return void
-(NSURLSessionTask*) deleteInboxForwarderWithId: (NSString*) _id
    completionHandler: (void (^)(NSError* error)) handler;


/// Delete inbox forwarders
/// Delete inbox forwarders. Accepts optional inboxId filter.
///
/// @param inboxId Optional inbox id to attach forwarder to (optional)
/// 
///  code:204 message:"No Content"
///
/// @return void
-(NSURLSessionTask*) deleteInboxForwardersWithInboxId: (NSString*) inboxId
    completionHandler: (void (^)(NSError* error)) handler;


/// Get an inbox forwarder
/// Get inbox ruleset
///
/// @param _id ID of inbox forwarder
/// 
///  code:200 message:"OK"
///
/// @return OAIInboxForwarderDto*
-(NSURLSessionTask*) getInboxForwarderWithId: (NSString*) _id
    completionHandler: (void (^)(OAIInboxForwarderDto* output, NSError* error)) handler;


/// Get an inbox forwarder event list
/// Get inbox ruleset events
///
/// @param _id ID of inbox forwarder
/// @param page Optional page index in inbox forwarder event list pagination (optional) (default to @0)
/// @param size Optional page size in inbox forwarder event list pagination (optional) (default to @20)
/// @param sort Optional createdAt sort direction ASC or DESC (optional) (default to @"ASC")
/// 
///  code:200 message:"OK"
///
/// @return OAIPageInboxForwarderEvents*
-(NSURLSessionTask*) getInboxForwarderEventsWithId: (NSString*) _id
    page: (NSNumber*) page
    size: (NSNumber*) size
    sort: (NSString*) sort
    completionHandler: (void (^)(OAIPageInboxForwarderEvents* output, NSError* error)) handler;


/// List inbox forwarders
/// List all forwarders attached to an inbox
///
/// @param inboxId Optional inbox id to get forwarders from (optional)
/// @param page Optional page index in inbox forwarder list pagination (optional) (default to @0)
/// @param size Optional page size in inbox forwarder list pagination (optional) (default to @20)
/// @param sort Optional createdAt sort direction ASC or DESC (optional) (default to @"ASC")
/// @param searchFilter Optional search filter (optional)
/// @param since Filter by created at after the given timestamp (optional)
/// @param before Filter by created at before the given timestamp (optional)
/// 
///  code:200 message:"OK"
///
/// @return OAIPageInboxForwarderDto*
-(NSURLSessionTask*) getInboxForwardersWithInboxId: (NSString*) inboxId
    page: (NSNumber*) page
    size: (NSNumber*) size
    sort: (NSString*) sort
    searchFilter: (NSString*) searchFilter
    since: (NSDate*) since
    before: (NSDate*) before
    completionHandler: (void (^)(OAIPageInboxForwarderDto* output, NSError* error)) handler;


/// Test an inbox forwarder
/// Test an inbox forwarder
///
/// @param _id ID of inbox forwarder
/// @param inboxForwarderTestOptions 
/// 
///  code:200 message:"OK"
///
/// @return OAIInboxForwarderTestResult*
-(NSURLSessionTask*) testInboxForwarderWithId: (NSString*) _id
    inboxForwarderTestOptions: (OAIInboxForwarderTestOptions*) inboxForwarderTestOptions
    completionHandler: (void (^)(OAIInboxForwarderTestResult* output, NSError* error)) handler;


/// Test inbox forwarders for inbox
/// Test inbox forwarders for inbox
///
/// @param inboxId ID of inbox
/// @param inboxForwarderTestOptions 
/// 
///  code:200 message:"OK"
///
/// @return OAIInboxForwarderTestResult*
-(NSURLSessionTask*) testInboxForwardersForInboxWithInboxId: (NSString*) inboxId
    inboxForwarderTestOptions: (OAIInboxForwarderTestOptions*) inboxForwarderTestOptions
    completionHandler: (void (^)(OAIInboxForwarderTestResult* output, NSError* error)) handler;


/// Test new inbox forwarder
/// Test new inbox forwarder
///
/// @param testNewInboxForwarderOptions 
/// 
///  code:200 message:"OK"
///
/// @return OAIInboxForwarderTestResult*
-(NSURLSessionTask*) testNewInboxForwarderWithTestNewInboxForwarderOptions: (OAITestNewInboxForwarderOptions*) testNewInboxForwarderOptions
    completionHandler: (void (^)(OAIInboxForwarderTestResult* output, NSError* error)) handler;


/// Update an inbox forwarder
/// Update inbox ruleset
///
/// @param _id ID of inbox forwarder
/// @param createInboxForwarderOptions 
/// 
///  code:200 message:"OK"
///
/// @return OAIInboxForwarderDto*
-(NSURLSessionTask*) updateInboxForwarderWithId: (NSString*) _id
    createInboxForwarderOptions: (OAICreateInboxForwarderOptions*) createInboxForwarderOptions
    completionHandler: (void (^)(OAIInboxForwarderDto* output, NSError* error)) handler;



@end
