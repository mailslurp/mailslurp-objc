#import <Foundation/Foundation.h>
#import "OAIEmail.h"
#import "OAIEmailPreview.h"
#import "OAIMatchOptions.h"
#import "OAIWaitForConditions.h"
#import "OAIApi.h"

/**
* MailSlurp API
* MailSlurp is an API for sending and receiving emails from dynamically allocated email addresses. It's designed for developers and QA teams to test applications, process inbound emails, send templated notifications, attachments, and more.  ## Resources  - [Homepage](https://www.mailslurp.com) - Get an [API KEY](https://app.mailslurp.com/sign-up/) - Generated [SDK Clients](https://www.mailslurp.com/docs/) - [Examples](https://github.com/mailslurp/examples) repository
*
* The version of the OpenAPI document: 6.5.2
* Contact: contact@mailslurp.dev
*
* NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
* https://openapi-generator.tech
* Do not edit the class manually.
*/



@interface OAIWaitForControllerApi: NSObject <OAIApi>

extern NSString* kOAIWaitForControllerApiErrorDomain;
extern NSInteger kOAIWaitForControllerApiMissingParamErrorCode;

-(instancetype) initWithApiClient:(OAIApiClient *)apiClient NS_DESIGNATED_INITIALIZER;

/// Wait for an email to match the provided filter conditions such as subject contains keyword.
/// Generic waitFor method that will wait until an inbox meets given conditions or return immediately if already met
///
/// @param waitForConditions 
/// 
///  code:200 message:"OK"
///
/// @return NSArray<OAIEmailPreview>*
-(NSURLSessionTask*) waitForWithWaitForConditions: (OAIWaitForConditions*) waitForConditions
    completionHandler: (void (^)(NSArray<OAIEmailPreview>* output, NSError* error)) handler;


/// Wait for and return count number of emails. Hold connection until inbox count matches expected or timeout occurs
/// If inbox contains count or more emails at time of request then return count worth of emails. If not wait until the count is reached and return those or return an error if timeout is exceeded.
///
/// @param inboxId Id of the inbox we are fetching emails from
/// @param count Number of emails to wait for. Must be greater that 1
/// @param timeout Max milliseconds to wait (optional)
/// @param unreadOnly Optional filter for unread only (optional) (default to @(NO))
/// @param before Filter for emails that were received before the given timestamp (optional)
/// @param since Filter for emails that were received after the given timestamp (optional)
/// @param sort Sort direction (optional)
/// @param delay Max milliseconds delay between calls (optional)
/// 
///  code:200 message:"OK"
///
/// @return NSArray<OAIEmailPreview>*
-(NSURLSessionTask*) waitForEmailCountWithInboxId: (NSString*) inboxId
    count: (NSNumber*) count
    timeout: (NSNumber*) timeout
    unreadOnly: (NSNumber*) unreadOnly
    before: (NSDate*) before
    since: (NSDate*) since
    sort: (NSString*) sort
    delay: (NSNumber*) delay
    completionHandler: (void (^)(NSArray<OAIEmailPreview>* output, NSError* error)) handler;


/// Fetch inbox's latest email or if empty wait for an email to arrive
/// Will return either the last received email or wait for an email to arrive and return that. If you need to wait for an email for a non-empty inbox set `unreadOnly=true` or see the other receive methods such as `waitForNthEmail` or `waitForEmailCount`.
///
/// @param inboxId Id of the inbox we are fetching emails from (optional)
/// @param timeout Max milliseconds to wait (optional)
/// @param unreadOnly Optional filter for unread only. (optional) (default to @(NO))
/// @param before Filter for emails that were before after the given timestamp (optional)
/// @param since Filter for emails that were received after the given timestamp (optional)
/// @param sort Sort direction (optional)
/// @param delay Max milliseconds delay between calls (optional)
/// 
///  code:200 message:"OK"
///
/// @return OAIEmail*
-(NSURLSessionTask*) waitForLatestEmailWithInboxId: (NSString*) inboxId
    timeout: (NSNumber*) timeout
    unreadOnly: (NSNumber*) unreadOnly
    before: (NSDate*) before
    since: (NSDate*) since
    sort: (NSString*) sort
    delay: (NSNumber*) delay
    completionHandler: (void (^)(OAIEmail* output, NSError* error)) handler;


/// Wait or return list of emails that match simple matching patterns
/// Perform a search of emails in an inbox with the given patterns. If results match expected count then return or else retry the search until results are found or timeout is reached. Match options allow simple CONTAINS or EQUALS filtering on SUBJECT, TO, BCC, CC, and FROM. See the `MatchOptions` object for options. An example payload is `{ matches: [{field: 'SUBJECT',should:'CONTAIN',value:'needle'}] }`. You can use an array of matches and they will be applied sequentially to filter out emails. If you want to perform matches and extractions of content using Regex patterns see the EmailController `getEmailContentMatch` method.
///
/// @param inboxId Id of the inbox we are fetching emails from
/// @param count Number of emails to wait for. Must be greater or equal to 1
/// @param matchOptions 
/// @param before Filter for emails that were received before the given timestamp (optional)
/// @param since Filter for emails that were received after the given timestamp (optional)
/// @param sort Sort direction (optional)
/// @param delay Max milliseconds delay between calls (optional)
/// @param timeout Max milliseconds to wait (optional)
/// @param unreadOnly Optional filter for unread only (optional) (default to @(NO))
/// 
///  code:200 message:"OK"
///
/// @return NSArray<OAIEmailPreview>*
-(NSURLSessionTask*) waitForMatchingEmailsWithInboxId: (NSString*) inboxId
    count: (NSNumber*) count
    matchOptions: (OAIMatchOptions*) matchOptions
    before: (NSDate*) before
    since: (NSDate*) since
    sort: (NSString*) sort
    delay: (NSNumber*) delay
    timeout: (NSNumber*) timeout
    unreadOnly: (NSNumber*) unreadOnly
    completionHandler: (void (^)(NSArray<OAIEmailPreview>* output, NSError* error)) handler;


/// Wait for or return the first email that matches provided MatchOptions array
/// Perform a search of emails in an inbox with the given patterns. If a result if found then return or else retry the search until a result is found or timeout is reached. Match options allow simple CONTAINS or EQUALS filtering on SUBJECT, TO, BCC, CC, and FROM. See the `MatchOptions` object for options. An example payload is `{ matches: [{field: 'SUBJECT',should:'CONTAIN',value:'needle'}] }`. You can use an array of matches and they will be applied sequentially to filter out emails. If you want to perform matches and extractions of content using Regex patterns see the EmailController `getEmailContentMatch` method.
///
/// @param inboxId Id of the inbox we are matching an email for
/// @param matchOptions 
/// @param timeout Max milliseconds to wait (optional)
/// @param unreadOnly Optional filter for unread only (optional) (default to @(NO))
/// @param since Filter for emails that were received after the given timestamp (optional)
/// @param before Filter for emails that were received before the given timestamp (optional)
/// @param sort Sort direction (optional)
/// @param delay Max milliseconds delay between calls (optional)
/// 
///  code:200 message:"OK"
///
/// @return OAIEmail*
-(NSURLSessionTask*) waitForMatchingFirstEmailWithInboxId: (NSString*) inboxId
    matchOptions: (OAIMatchOptions*) matchOptions
    timeout: (NSNumber*) timeout
    unreadOnly: (NSNumber*) unreadOnly
    since: (NSDate*) since
    before: (NSDate*) before
    sort: (NSString*) sort
    delay: (NSNumber*) delay
    completionHandler: (void (^)(OAIEmail* output, NSError* error)) handler;


/// Wait for or fetch the email with a given index in the inbox specified. If index doesn't exist waits for it to exist or timeout to occur.
/// If nth email is already present in inbox then return it. If not hold the connection open until timeout expires or the nth email is received and returned.
///
/// @param inboxId Id of the inbox you are fetching emails from (optional)
/// @param index Zero based index of the email to wait for. If an inbox has 1 email already and you want to wait for the 2nd email pass index&#x3D;1 (optional) (default to @0)
/// @param timeout Max milliseconds to wait for the nth email if not already present (optional)
/// @param unreadOnly Optional filter for unread only (optional) (default to @(NO))
/// @param since Filter for emails that were received after the given timestamp (optional)
/// @param before Filter for emails that were received before the given timestamp (optional)
/// @param sort Sort direction (optional)
/// @param delay Max milliseconds delay between calls (optional)
/// 
///  code:200 message:"OK"
///
/// @return OAIEmail*
-(NSURLSessionTask*) waitForNthEmailWithInboxId: (NSString*) inboxId
    index: (NSNumber*) index
    timeout: (NSNumber*) timeout
    unreadOnly: (NSNumber*) unreadOnly
    since: (NSDate*) since
    before: (NSDate*) before
    sort: (NSString*) sort
    delay: (NSNumber*) delay
    completionHandler: (void (^)(OAIEmail* output, NSError* error)) handler;



@end
