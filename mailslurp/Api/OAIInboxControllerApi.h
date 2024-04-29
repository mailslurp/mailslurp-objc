#import <Foundation/Foundation.h>
#import "OAICountDto.h"
#import "OAICreateInboxDto.h"
#import "OAICreateInboxRulesetOptions.h"
#import "OAIEmail.h"
#import "OAIEmailPreview.h"
#import "OAIFlushExpiredInboxesResult.h"
#import "OAIImapAccessDetails.h"
#import "OAIImapSmtpAccessDetails.h"
#import "OAIInboxByEmailAddressResult.h"
#import "OAIInboxByNameResult.h"
#import "OAIInboxDto.h"
#import "OAIInboxExistsDto.h"
#import "OAIInboxIdsResult.h"
#import "OAIInboxRulesetDto.h"
#import "OAIPageDeliveryStatus.h"
#import "OAIPageEmailPreview.h"
#import "OAIPageInboxProjection.h"
#import "OAIPageInboxRulesetDto.h"
#import "OAIPageOrganizationInboxProjection.h"
#import "OAIPageScheduledJobs.h"
#import "OAIPageSentEmailProjection.h"
#import "OAIPageTrackingPixelProjection.h"
#import "OAIScheduledJobDto.h"
#import "OAISearchInboxesOptions.h"
#import "OAISendEmailOptions.h"
#import "OAISendSMTPEnvelopeOptions.h"
#import "OAISentEmailDto.h"
#import "OAISetInboxFavouritedOptions.h"
#import "OAISmtpAccessDetails.h"
#import "OAIUpdateInboxOptions.h"
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



@interface OAIInboxControllerApi: NSObject <OAIApi>

extern NSString* kOAIInboxControllerApiErrorDomain;
extern NSInteger kOAIInboxControllerApiMissingParamErrorCode;

-(instancetype) initWithApiClient:(OAIApiClient *)apiClient NS_DESIGNATED_INITIALIZER;

/// Cancel a scheduled email job
/// Get a scheduled email job and cancel it. Will fail if status of job is already cancelled, failed, or complete.
///
/// @param jobId 
/// 
///  code:200 message:"OK"
///
/// @return OAIScheduledJobDto*
-(NSURLSessionTask*) cancelScheduledJobWithJobId: (NSString*) jobId
    completionHandler: (void (^)(OAIScheduledJobDto* output, NSError* error)) handler;


/// Create an inbox email address. An inbox has a real email address and can send and receive emails. Inboxes can be either `SMTP` or `HTTP` inboxes.
/// Create a new inbox and with a randomized email address to send and receive from. Pass emailAddress parameter if you wish to use a specific email address. Creating an inbox is required before sending or receiving emails. If writing tests it is recommended that you create a new inbox during each test method so that it is unique and empty. 
///
/// @param emailAddress A custom email address to use with the inbox. Defaults to null. When null MailSlurp will assign a random email address to the inbox such as &#x60;123@mailslurp.com&#x60;. If you use the &#x60;useDomainPool&#x60; option when the email address is null it will generate an email address with a more varied domain ending such as &#x60;123@mailslurp.info&#x60; or &#x60;123@mailslurp.biz&#x60;. When a custom email address is provided the address is split into a domain and the domain is queried against your user. If you have created the domain in the MailSlurp dashboard and verified it you can use any email address that ends with the domain. Note domain types must match the inbox type - so &#x60;SMTP&#x60; inboxes will only work with &#x60;SMTP&#x60; type domains. Avoid &#x60;SMTP&#x60; inboxes if you need to send emails as they can only receive. Send an email to this address and the inbox will receive and store it for you. To retrieve the email use the Inbox and Email Controller endpoints with the inbox ID. (optional)
/// @param tags Tags that inbox has been tagged with. Tags can be added to inboxes to group different inboxes within an account. You can also search for inboxes by tag in the dashboard UI. (optional)
/// @param name Optional name of the inbox. Displayed in the dashboard for easier search and used as the sender name when sending emails. (optional)
/// @param _description Optional description of the inbox for labelling purposes. Is shown in the dashboard and can be used with (optional)
/// @param useDomainPool Use the MailSlurp domain name pool with this inbox when creating the email address. Defaults to null. If enabled the inbox will be an email address with a domain randomly chosen from a list of the MailSlurp domains. This is useful when the default &#x60;@mailslurp.com&#x60; email addresses used with inboxes are blocked or considered spam by a provider or receiving service. When domain pool is enabled an email address will be generated ending in &#x60;@mailslurp.{world,info,xyz,...}&#x60; . This means a TLD is randomly selecting from a list of &#x60;.biz&#x60;, &#x60;.info&#x60;, &#x60;.xyz&#x60; etc to add variance to the generated email addresses. When null or false MailSlurp uses the default behavior of &#x60;@mailslurp.com&#x60; or custom email address provided by the emailAddress field. Note this feature is only available for &#x60;HTTP&#x60; inbox types. (optional)
/// @param favourite Is the inbox a favorite. Marking an inbox as a favorite is typically done in the dashboard for quick access or filtering (optional)
/// @param expiresAt Optional inbox expiration date. If null then this inbox is permanent and the emails in it won&#39;t be deleted. If an expiration date is provided or is required by your plan the inbox will be closed when the expiration time is reached. Expired inboxes still contain their emails but can no longer send or receive emails. An ExpiredInboxRecord is created when an inbox and the email address and inbox ID are recorded. The expiresAt property is a timestamp string in ISO DateTime Format yyyy-MM-dd&#39;T&#39;HH:mm:ss.SSSXXX. (optional)
/// @param expiresIn Number of milliseconds that inbox should exist for (optional)
/// @param allowTeamAccess DEPRECATED (team access is always true). Grant team access to this inbox and the emails that belong to it for team members of your organization. (optional)
/// @param inboxType HTTP (default) or SMTP inbox type. HTTP inboxes are default and best solution for most cases. SMTP inboxes are more reliable for public inbound email consumption (but do not support sending emails). When using custom domains the domain type must match the inbox type. HTTP inboxes are processed by AWS SES while SMTP inboxes use a custom mail server running at &#x60;mx.mailslurp.com&#x60;. (optional)
/// @param virtualInbox Virtual inbox prevents any outbound emails from being sent. It creates sent email records but will never send real emails to recipients. Great for testing and faking email sending. (optional)
/// @param useShortAddress Use a shorter email address under 31 characters (optional)
/// @param domainId ID of custom domain to use for email address. (optional)
/// @param domainName FQDN domain name for the domain you have verified. Will be appended with a randomly assigned recipient name. Use the &#x60;emailAddress&#x60; option instead to specify the full custom inbox. (optional)
/// @param prefix Prefix to add before the email address for easier labelling or identification. (optional)
/// 
///  code:201 message:"Created"
///
/// @return OAIInboxDto*
-(NSURLSessionTask*) createInboxWithEmailAddress: (NSString*) emailAddress
    tags: (NSArray<NSString*>*) tags
    name: (NSString*) name
    _description: (NSString*) _description
    useDomainPool: (NSNumber*) useDomainPool
    favourite: (NSNumber*) favourite
    expiresAt: (NSDate*) expiresAt
    expiresIn: (NSNumber*) expiresIn
    allowTeamAccess: (NSNumber*) allowTeamAccess
    inboxType: (NSString*) inboxType
    virtualInbox: (NSNumber*) virtualInbox
    useShortAddress: (NSNumber*) useShortAddress
    domainId: (NSString*) domainId
    domainName: (NSString*) domainName
    prefix: (NSString*) prefix
    completionHandler: (void (^)(OAIInboxDto* output, NSError* error)) handler;


/// Create an inbox ruleset
/// Create a new inbox rule for forwarding, blocking, and allowing emails when sending and receiving
///
/// @param inboxId inboxId
/// @param createInboxRulesetOptions 
/// 
///  code:200 message:"OK"
///
/// @return OAIInboxRulesetDto*
-(NSURLSessionTask*) createInboxRulesetWithInboxId: (NSString*) inboxId
    createInboxRulesetOptions: (OAICreateInboxRulesetOptions*) createInboxRulesetOptions
    completionHandler: (void (^)(OAIInboxRulesetDto* output, NSError* error)) handler;


/// Create an inbox with default options. Uses MailSlurp domain pool address and is private.
/// 
///
/// 
///  code:201 message:"Created"
///
/// @return OAIInboxDto*
-(NSURLSessionTask*) createInboxWithDefaultsWithCompletionHandler: 
    (void (^)(OAIInboxDto* output, NSError* error)) handler;


/// Create an inbox with options. Extended options for inbox creation.
/// Additional endpoint that allows inbox creation with request body options. Can be more flexible that other methods for some clients.
///
/// @param createInboxDto 
/// 
///  code:201 message:"Created"
///
/// @return OAIInboxDto*
-(NSURLSessionTask*) createInboxWithOptionsWithCreateInboxDto: (OAICreateInboxDto*) createInboxDto
    completionHandler: (void (^)(OAIInboxDto* output, NSError* error)) handler;


/// Delete all emails in a given inboxes.
/// Deletes all emails in an inbox. Be careful as emails cannot be recovered
///
/// @param inboxId 
/// 
///  code:204 message:"No Content"
///
/// @return void
-(NSURLSessionTask*) deleteAllInboxEmailsWithInboxId: (NSString*) inboxId
    completionHandler: (void (^)(NSError* error)) handler;


/// Delete all inboxes
/// Permanently delete all inboxes and associated email addresses. This will also delete all emails within the inboxes. Be careful as inboxes cannot be recovered once deleted. Note: deleting inboxes will not impact your usage limits. Monthly inbox creation limits are based on how many inboxes were created in the last 30 days, not how many inboxes you currently have.
///
/// 
///  code:204 message:"No Content"
///
/// @return void
-(NSURLSessionTask*) deleteAllInboxesWithCompletionHandler: 
    (void (^)(NSError* error)) handler;


/// Delete inboxes by description
/// Permanently delete all inboxes by description
///
/// @param _description 
/// 
///  code:204 message:"No Content"
///
/// @return void
-(NSURLSessionTask*) deleteAllInboxesByDescriptionWithDescription: (NSString*) _description
    completionHandler: (void (^)(NSError* error)) handler;


/// Delete inboxes by name
/// Permanently delete all inboxes by name
///
/// @param name 
/// 
///  code:204 message:"No Content"
///
/// @return void
-(NSURLSessionTask*) deleteAllInboxesByNameWithName: (NSString*) name
    completionHandler: (void (^)(NSError* error)) handler;


/// Delete inboxes by tag
/// Permanently delete all inboxes by tag
///
/// @param tag 
/// 
///  code:204 message:"No Content"
///
/// @return void
-(NSURLSessionTask*) deleteAllInboxesByTagWithTag: (NSString*) tag
    completionHandler: (void (^)(NSError* error)) handler;


/// Delete inbox
/// Permanently delete an inbox and associated email address as well as all emails within the given inbox. This action cannot be undone. Note: deleting an inbox will not affect your account usage. Monthly inbox usage is based on how many inboxes you create within 30 days, not how many exist at time of request.
///
/// @param inboxId 
/// 
///  code:204 message:"No Content"
///
/// @return void
-(NSURLSessionTask*) deleteInboxWithInboxId: (NSString*) inboxId
    completionHandler: (void (^)(NSError* error)) handler;


/// Does inbox exist
/// Check if inboxes exist by email address. Useful if you are sending emails to mailslurp addresses
///
/// @param emailAddress Email address
/// @param allowCatchAll  (optional)
/// 
///  code:200 message:"OK"
///
/// @return OAIInboxExistsDto*
-(NSURLSessionTask*) doesInboxExistWithEmailAddress: (NSString*) emailAddress
    allowCatchAll: (NSNumber*) allowCatchAll
    completionHandler: (void (^)(OAIInboxExistsDto* output, NSError* error)) handler;


/// Remove expired inboxes
/// Remove any expired inboxes for your account (instead of waiting for scheduled removal on server)
///
/// @param before Optional expired at before flag to flush expired inboxes that have expired before the given time (optional)
/// 
///  code:200 message:"OK"
///
/// @return OAIFlushExpiredInboxesResult*
-(NSURLSessionTask*) flushExpiredWithBefore: (NSDate*) before
    completionHandler: (void (^)(OAIFlushExpiredInboxesResult* output, NSError* error)) handler;


/// List All Inboxes Paginated
/// List inboxes in paginated form. The results are available on the `content` property of the returned object. This method allows for page index (zero based), page size (how many results to return), and a sort direction (based on createdAt time). You Can also filter by whether an inbox is favorited or use email address pattern. This method is the recommended way to query inboxes. The alternative `getInboxes` method returns a full list of inboxes but is limited to 100 results.
///
/// @param page Optional page index in list pagination (optional) (default to @0)
/// @param size Optional page size in list pagination (optional) (default to @20)
/// @param sort Optional createdAt sort direction ASC or DESC (optional) (default to @"ASC")
/// @param favourite Optionally filter results for favourites only (optional) (default to @(NO))
/// @param search Optionally filter by search words partial matching ID, tags, name, and email address (optional)
/// @param tag Optionally filter by tags. Will return inboxes that include given tags (optional)
/// @param teamAccess DEPRECATED. Optionally filter by team access. (optional)
/// @param since Optional filter by created after given date time (optional)
/// @param before Optional filter by created before given date time (optional)
/// @param inboxType Optional filter by inbox type (optional)
/// @param inboxFunction Optional filter by inbox function (optional)
/// @param domainId Optional domain ID filter (optional)
/// 
///  code:200 message:"OK"
///
/// @return OAIPageInboxProjection*
-(NSURLSessionTask*) getAllInboxesWithPage: (NSNumber*) page
    size: (NSNumber*) size
    sort: (NSString*) sort
    favourite: (NSNumber*) favourite
    search: (NSString*) search
    tag: (NSString*) tag
    teamAccess: (NSNumber*) teamAccess
    since: (NSDate*) since
    before: (NSDate*) before
    inboxType: (NSString*) inboxType
    inboxFunction: (NSString*) inboxFunction
    domainId: (NSString*) domainId
    completionHandler: (void (^)(OAIPageInboxProjection* output, NSError* error)) handler;


/// List All Inboxes Offset Paginated
/// List inboxes in paginated form. The results are available on the `content` property of the returned object. This method allows for page index (zero based), page size (how many results to return), and a sort direction (based on createdAt time). You Can also filter by whether an inbox is favorited or use email address pattern. This method is the recommended way to query inboxes. The alternative `getInboxes` method returns a full list of inboxes but is limited to 100 results.
///
/// @param page Optional page index in list pagination (optional) (default to @0)
/// @param size Optional page size in list pagination (optional) (default to @20)
/// @param sort Optional createdAt sort direction ASC or DESC (optional) (default to @"ASC")
/// @param favourite Optionally filter results for favourites only (optional) (default to @(NO))
/// @param search Optionally filter by search words partial matching ID, tags, name, and email address (optional)
/// @param tag Optionally filter by tags. Will return inboxes that include given tags (optional)
/// @param teamAccess DEPRECATED. Optionally filter by team access. (optional)
/// @param since Optional filter by created after given date time (optional)
/// @param before Optional filter by created before given date time (optional)
/// @param inboxType Optional filter by inbox type (optional)
/// @param inboxFunction Optional filter by inbox function (optional)
/// @param domainId Optional domain ID filter (optional)
/// 
///  code:200 message:"OK"
///
/// @return OAIPageInboxProjection*
-(NSURLSessionTask*) getAllInboxesOffsetPaginatedWithPage: (NSNumber*) page
    size: (NSNumber*) size
    sort: (NSString*) sort
    favourite: (NSNumber*) favourite
    search: (NSString*) search
    tag: (NSString*) tag
    teamAccess: (NSNumber*) teamAccess
    since: (NSDate*) since
    before: (NSDate*) before
    inboxType: (NSString*) inboxType
    inboxFunction: (NSString*) inboxFunction
    domainId: (NSString*) domainId
    completionHandler: (void (^)(OAIPageInboxProjection* output, NSError* error)) handler;


/// Get all scheduled email sending jobs for account
/// Schedule sending of emails using scheduled jobs. These can be inbox or account level.
///
/// @param page Optional page index in scheduled job list pagination (optional) (default to @0)
/// @param size Optional page size in scheduled job list pagination (optional) (default to @20)
/// @param sort Optional createdAt sort direction ASC or DESC (optional) (default to @"ASC")
/// @param since Filter by created at after the given timestamp (optional)
/// @param before Filter by created at before the given timestamp (optional)
/// 
///  code:200 message:"OK"
///
/// @return OAIPageScheduledJobs*
-(NSURLSessionTask*) getAllScheduledJobsWithPage: (NSNumber*) page
    size: (NSNumber*) size
    sort: (NSString*) sort
    since: (NSDate*) since
    before: (NSDate*) before
    completionHandler: (void (^)(OAIPageScheduledJobs* output, NSError* error)) handler;


/// 
/// Get all email delivery statuses for an inbox
///
/// @param inboxId 
/// @param page Optional page index in delivery status list pagination (optional) (default to @0)
/// @param size Optional page size in delivery status list pagination (optional) (default to @20)
/// @param sort Optional createdAt sort direction ASC or DESC (optional) (default to @"ASC")
/// @param since Filter by created at after the given timestamp (optional)
/// @param before Filter by created at before the given timestamp (optional)
/// 
///  code:200 message:"OK"
///
/// @return OAIPageDeliveryStatus*
-(NSURLSessionTask*) getDeliveryStatusesByInboxIdWithInboxId: (NSString*) inboxId
    page: (NSNumber*) page
    size: (NSNumber*) size
    sort: (NSString*) sort
    since: (NSDate*) since
    before: (NSDate*) before
    completionHandler: (void (^)(OAIPageDeliveryStatus* output, NSError* error)) handler;


/// Get emails in an Inbox. This method is not idempotent as it allows retries and waits if you want certain conditions to be met before returning. For simple listing and sorting of known emails use the email controller instead.
/// List emails that an inbox has received. Only emails that are sent to the inbox's email address will appear in the inbox. It may take several seconds for any email you send to an inbox's email address to appear in the inbox. To make this endpoint wait for a minimum number of emails use the `minCount` parameter. The server will retry the inbox database until the `minCount` is satisfied or the `retryTimeout` is reached
///
/// @param inboxId Id of inbox that emails belongs to
/// @param size Alias for limit. Assessed first before assessing any passed limit. (optional)
/// @param limit Limit the result set, ordered by received date time sort direction. Maximum 100. For more listing options see the email controller (optional)
/// @param sort Sort the results by received date and direction ASC or DESC (optional)
/// @param retryTimeout Maximum milliseconds to spend retrying inbox database until minCount emails are returned (optional)
/// @param delayTimeout  (optional)
/// @param minCount Minimum acceptable email count. Will cause request to hang (and retry) until minCount is satisfied or retryTimeout is reached. (optional)
/// @param unreadOnly  (optional)
/// @param before Exclude emails received after this ISO 8601 date time (optional)
/// @param since Exclude emails received before this ISO 8601 date time (optional)
/// 
///  code:200 message:"OK"
///
/// @return NSArray<OAIEmailPreview>*
-(NSURLSessionTask*) getEmailsWithInboxId: (NSString*) inboxId
    size: (NSNumber*) size
    limit: (NSNumber*) limit
    sort: (NSString*) sort
    retryTimeout: (NSNumber*) retryTimeout
    delayTimeout: (NSNumber*) delayTimeout
    minCount: (NSNumber*) minCount
    unreadOnly: (NSNumber*) unreadOnly
    before: (NSDate*) before
    since: (NSDate*) since
    completionHandler: (void (^)(NSArray<OAIEmailPreview>* output, NSError* error)) handler;


/// 
/// Get IMAP access usernames and passwords
///
/// @param inboxId Inbox ID (optional)
/// 
///  code:200 message:"OK"
///
/// @return OAIImapAccessDetails*
-(NSURLSessionTask*) getImapAccessWithInboxId: (NSString*) inboxId
    completionHandler: (void (^)(OAIImapAccessDetails* output, NSError* error)) handler;


/// 
/// Get IMAP and SMTP access usernames and passwords
///
/// @param inboxId Inbox ID (optional)
/// 
///  code:200 message:"OK"
///
/// @return OAIImapSmtpAccessDetails*
-(NSURLSessionTask*) getImapSmtpAccessWithInboxId: (NSString*) inboxId
    completionHandler: (void (^)(OAIImapSmtpAccessDetails* output, NSError* error)) handler;


/// Get Inbox. Returns properties of an inbox.
/// Returns an inbox's properties, including its email address and ID.
///
/// @param inboxId 
/// 
///  code:200 message:"OK"
///
/// @return OAIInboxDto*
-(NSURLSessionTask*) getInboxWithInboxId: (NSString*) inboxId
    completionHandler: (void (^)(OAIInboxDto* output, NSError* error)) handler;


/// Search for an inbox with the provided email address
/// Get a inbox result by email address
///
/// @param emailAddress 
/// 
///  code:200 message:"OK"
///
/// @return OAIInboxByEmailAddressResult*
-(NSURLSessionTask*) getInboxByEmailAddressWithEmailAddress: (NSString*) emailAddress
    completionHandler: (void (^)(OAIInboxByEmailAddressResult* output, NSError* error)) handler;


/// Search for an inbox with the given name
/// Get a inbox result by name
///
/// @param name 
/// 
///  code:200 message:"OK"
///
/// @return OAIInboxByNameResult*
-(NSURLSessionTask*) getInboxByNameWithName: (NSString*) name
    completionHandler: (void (^)(OAIInboxByNameResult* output, NSError* error)) handler;


/// Get total inbox count
/// 
///
/// 
///  code:200 message:"OK"
///
/// @return OAICountDto*
-(NSURLSessionTask*) getInboxCountWithCompletionHandler: 
    (void (^)(OAICountDto* output, NSError* error)) handler;


/// Get email count in inbox
/// 
///
/// @param inboxId Id of inbox that emails belongs to
/// 
///  code:200 message:"OK"
///
/// @return OAICountDto*
-(NSURLSessionTask*) getInboxEmailCountWithInboxId: (NSString*) inboxId
    completionHandler: (void (^)(OAICountDto* output, NSError* error)) handler;


/// Get inbox emails paginated
/// Get a paginated list of emails in an inbox. Does not hold connections open.
///
/// @param inboxId Id of inbox that emails belongs to
/// @param page Optional page index in inbox emails list pagination (optional) (default to @0)
/// @param size Optional page size in inbox emails list pagination (optional) (default to @20)
/// @param sort Optional createdAt sort direction ASC or DESC (optional) (default to @"ASC")
/// @param since Optional filter by received after given date time (optional)
/// @param before Optional filter by received before given date time (optional)
/// 
///  code:200 message:"OK"
///
/// @return OAIPageEmailPreview*
-(NSURLSessionTask*) getInboxEmailsPaginatedWithInboxId: (NSString*) inboxId
    page: (NSNumber*) page
    size: (NSNumber*) size
    sort: (NSString*) sort
    since: (NSDate*) since
    before: (NSDate*) before
    completionHandler: (void (^)(OAIPageEmailPreview* output, NSError* error)) handler;


/// Get all inbox IDs
/// Get list of inbox IDs
///
/// 
///  code:200 message:"OK"
///
/// @return OAIInboxIdsResult*
-(NSURLSessionTask*) getInboxIdsWithCompletionHandler: 
    (void (^)(OAIInboxIdsResult* output, NSError* error)) handler;


/// Get Inbox Sent Emails
/// Returns an inbox's sent email receipts. Call individual sent email endpoints for more details. Note for privacy reasons the full body of sent emails is never stored. An MD5 hash hex is available for comparison instead.
///
/// @param inboxId 
/// @param page Optional page index in inbox sent email list pagination (optional) (default to @0)
/// @param size Optional page size in inbox sent email list pagination (optional) (default to @20)
/// @param sort Optional createdAt sort direction ASC or DESC (optional) (default to @"ASC")
/// @param searchFilter Optional sent email search (optional)
/// @param since Optional filter by sent after given date time (optional)
/// @param before Optional filter by sent before given date time (optional)
/// 
///  code:200 message:"OK"
///
/// @return OAIPageSentEmailProjection*
-(NSURLSessionTask*) getInboxSentEmailsWithInboxId: (NSString*) inboxId
    page: (NSNumber*) page
    size: (NSNumber*) size
    sort: (NSString*) sort
    searchFilter: (NSString*) searchFilter
    since: (NSDate*) since
    before: (NSDate*) before
    completionHandler: (void (^)(OAIPageSentEmailProjection* output, NSError* error)) handler;


/// Get inbox tags
/// Get all inbox tags
///
/// 
///  code:200 message:"OK"
///
/// @return NSArray<NSString*>*
-(NSURLSessionTask*) getInboxTagsWithCompletionHandler: 
    (void (^)(NSArray<NSString*>* output, NSError* error)) handler;


/// List Inboxes and email addresses
/// List the inboxes you have created. Note use of the more advanced `getAllInboxes` is recommended and allows paginated access using a limit and sort parameter.
///
/// @param size Optional result size limit. Note an automatic limit of 100 results is applied. See the paginated &#x60;getAllEmails&#x60; for larger queries. (optional) (default to @100)
/// @param sort Optional createdAt sort direction ASC or DESC (optional) (default to @"ASC")
/// @param since Optional filter by created after given date time (optional)
/// @param excludeCatchAllInboxes Optional exclude catch all inboxes (optional)
/// @param before Optional filter by created before given date time (optional)
/// 
///  code:200 message:"OK"
///
/// @return NSArray<OAIInboxDto>*
-(NSURLSessionTask*) getInboxesWithSize: (NSNumber*) size
    sort: (NSString*) sort
    since: (NSDate*) since
    excludeCatchAllInboxes: (NSNumber*) excludeCatchAllInboxes
    before: (NSDate*) before
    completionHandler: (void (^)(NSArray<OAIInboxDto>* output, NSError* error)) handler;


/// Get latest email in an inbox. Use `WaitForController` to get emails that may not have arrived yet.
/// Get the newest email in an inbox or wait for one to arrive
///
/// @param inboxId ID of the inbox you want to get the latest email from
/// @param timeoutMillis Timeout milliseconds to wait for latest email
/// 
///  code:200 message:"OK"
///
/// @return OAIEmail*
-(NSURLSessionTask*) getLatestEmailInInboxWithInboxId: (NSString*) inboxId
    timeoutMillis: (NSNumber*) timeoutMillis
    completionHandler: (void (^)(OAIEmail* output, NSError* error)) handler;


/// List Organization Inboxes Paginated
/// List organization inboxes in paginated form. These are inboxes created with `allowTeamAccess` flag enabled. Organization inboxes are `readOnly` for non-admin users. The results are available on the `content` property of the returned object. This method allows for page index (zero based), page size (how many results to return), and a sort direction (based on createdAt time). 
///
/// @param page Optional page index in list pagination (optional) (default to @0)
/// @param size Optional page size in list pagination (optional) (default to @20)
/// @param sort Optional createdAt sort direction ASC or DESC (optional) (default to @"ASC")
/// @param searchFilter Optional search filter (optional)
/// @param since Optional filter by created after given date time (optional)
/// @param before Optional filter by created before given date time (optional)
/// 
///  code:200 message:"OK"
///
/// @return OAIPageOrganizationInboxProjection*
-(NSURLSessionTask*) getOrganizationInboxesWithPage: (NSNumber*) page
    size: (NSNumber*) size
    sort: (NSString*) sort
    searchFilter: (NSString*) searchFilter
    since: (NSDate*) since
    before: (NSDate*) before
    completionHandler: (void (^)(OAIPageOrganizationInboxProjection* output, NSError* error)) handler;


/// Get a scheduled email job
/// Get a scheduled email job details.
///
/// @param jobId 
/// 
///  code:200 message:"OK"
///
/// @return OAIScheduledJobDto*
-(NSURLSessionTask*) getScheduledJobWithJobId: (NSString*) jobId
    completionHandler: (void (^)(OAIScheduledJobDto* output, NSError* error)) handler;


/// Get all scheduled email sending jobs for the inbox
/// Schedule sending of emails using scheduled jobs.
///
/// @param inboxId 
/// @param page Optional page index in scheduled job list pagination (optional) (default to @0)
/// @param size Optional page size in scheduled job list pagination (optional) (default to @20)
/// @param sort Optional createdAt sort direction ASC or DESC (optional) (default to @"ASC")
/// @param since Filter by created at after the given timestamp (optional)
/// @param before Filter by created at before the given timestamp (optional)
/// 
///  code:200 message:"OK"
///
/// @return OAIPageScheduledJobs*
-(NSURLSessionTask*) getScheduledJobsByInboxIdWithInboxId: (NSString*) inboxId
    page: (NSNumber*) page
    size: (NSNumber*) size
    sort: (NSString*) sort
    since: (NSDate*) since
    before: (NSDate*) before
    completionHandler: (void (^)(OAIPageScheduledJobs* output, NSError* error)) handler;


/// 
/// Get SMTP access usernames and passwords
///
/// @param inboxId Inbox ID (optional)
/// 
///  code:200 message:"OK"
///
/// @return OAISmtpAccessDetails*
-(NSURLSessionTask*) getSmtpAccessWithInboxId: (NSString*) inboxId
    completionHandler: (void (^)(OAISmtpAccessDetails* output, NSError* error)) handler;


/// List inbox rulesets
/// List all rulesets attached to an inbox
///
/// @param inboxId 
/// @param page Optional page index in inbox ruleset list pagination (optional) (default to @0)
/// @param size Optional page size in inbox ruleset list pagination (optional) (default to @20)
/// @param sort Optional createdAt sort direction ASC or DESC (optional) (default to @"ASC")
/// @param searchFilter Optional search filter (optional)
/// @param since Optional filter by created after given date time (optional)
/// @param before Optional filter by created before given date time (optional)
/// 
///  code:200 message:"OK"
///
/// @return OAIPageInboxRulesetDto*
-(NSURLSessionTask*) listInboxRulesetsWithInboxId: (NSString*) inboxId
    page: (NSNumber*) page
    size: (NSNumber*) size
    sort: (NSString*) sort
    searchFilter: (NSString*) searchFilter
    since: (NSDate*) since
    before: (NSDate*) before
    completionHandler: (void (^)(OAIPageInboxRulesetDto* output, NSError* error)) handler;


/// List inbox tracking pixels
/// List all tracking pixels sent from an inbox
///
/// @param inboxId 
/// @param page Optional page index in inbox tracking pixel list pagination (optional) (default to @0)
/// @param size Optional page size in inbox tracking pixel list pagination (optional) (default to @20)
/// @param sort Optional createdAt sort direction ASC or DESC (optional) (default to @"ASC")
/// @param searchFilter Optional search filter (optional)
/// @param since Optional filter by created after given date time (optional)
/// @param before Optional filter by created before given date time (optional)
/// 
///  code:200 message:"OK"
///
/// @return OAIPageTrackingPixelProjection*
-(NSURLSessionTask*) listInboxTrackingPixelsWithInboxId: (NSString*) inboxId
    page: (NSNumber*) page
    size: (NSNumber*) size
    sort: (NSString*) sort
    searchFilter: (NSString*) searchFilter
    since: (NSDate*) since
    before: (NSDate*) before
    completionHandler: (void (^)(OAIPageTrackingPixelProjection* output, NSError* error)) handler;


/// Search all inboxes and return matching inboxes
/// Search inboxes and return in paginated form. The results are available on the `content` property of the returned object. This method allows for page index (zero based), page size (how many results to return), and a sort direction (based on createdAt time). You Can also filter by whether an inbox is favorited or use email address pattern. This method is the recommended way to query inboxes. The alternative `getInboxes` method returns a full list of inboxes but is limited to 100 results.
///
/// @param searchInboxesOptions 
/// 
///  code:200 message:"OK"
///
/// @return OAIPageInboxProjection*
-(NSURLSessionTask*) searchInboxesWithSearchInboxesOptions: (OAISearchInboxesOptions*) searchInboxesOptions
    completionHandler: (void (^)(OAIPageInboxProjection* output, NSError* error)) handler;


/// Send Email
/// Send an email from an inbox's email address.  The request body should contain the `SendEmailOptions` that include recipients, attachments, body etc. See `SendEmailOptions` for all available properties. Note the `inboxId` refers to the inbox's id not the inbox's email address. See https://www.mailslurp.com/guides/ for more information on how to send emails. This method does not return a sent email entity due to legacy reasons. To send and get a sent email as returned response use the sister method `sendEmailAndConfirm`.
///
/// @param inboxId ID of the inbox you want to send the email from
/// @param sendEmailOptions 
/// 
///  code:201 message:"Created"
///
/// @return void
-(NSURLSessionTask*) sendEmailWithInboxId: (NSString*) inboxId
    sendEmailOptions: (OAISendEmailOptions*) sendEmailOptions
    completionHandler: (void (^)(NSError* error)) handler;


/// Send email and return sent confirmation
/// Sister method for standard `sendEmail` method with the benefit of returning a `SentEmail` entity confirming the successful sending of the email with a link to the sent object created for it.
///
/// @param inboxId ID of the inbox you want to send the email from
/// @param sendEmailOptions 
/// 
///  code:201 message:"Created"
///
/// @return OAISentEmailDto*
-(NSURLSessionTask*) sendEmailAndConfirmWithInboxId: (NSString*) inboxId
    sendEmailOptions: (OAISendEmailOptions*) sendEmailOptions
    completionHandler: (void (^)(OAISentEmailDto* output, NSError* error)) handler;


/// Send email with queue
/// Send an email using a queue. Will place the email onto a queue that will then be processed and sent. Use this queue method to enable any failed email sending to be recovered. This will prevent lost emails when sending if your account encounters a block or payment issue.
///
/// @param inboxId ID of the inbox you want to send the email from
/// @param validateBeforeEnqueue Validate before adding to queue
/// @param sendEmailOptions 
/// 
///  code:201 message:"Created"
///
/// @return void
-(NSURLSessionTask*) sendEmailWithQueueWithInboxId: (NSString*) inboxId
    validateBeforeEnqueue: (NSNumber*) validateBeforeEnqueue
    sendEmailOptions: (OAISendEmailOptions*) sendEmailOptions
    completionHandler: (void (^)(NSError* error)) handler;


/// Send email using an SMTP mail envelope and message body and return sent confirmation
/// Send email using an SMTP envelope containing RCPT TO, MAIL FROM, and a SMTP BODY.
///
/// @param inboxId ID of the inbox you want to send the email from
/// @param sendSMTPEnvelopeOptions 
/// 
///  code:201 message:"Created"
///
/// @return OAISentEmailDto*
-(NSURLSessionTask*) sendSmtpEnvelopeWithInboxId: (NSString*) inboxId
    sendSMTPEnvelopeOptions: (OAISendSMTPEnvelopeOptions*) sendSMTPEnvelopeOptions
    completionHandler: (void (^)(OAISentEmailDto* output, NSError* error)) handler;


/// Send a test email to inbox
/// Send an inbox a test email to test email receiving is working
///
/// @param inboxId 
/// 
///  code:204 message:"No Content"
///
/// @return void
-(NSURLSessionTask*) sendTestEmailWithInboxId: (NSString*) inboxId
    completionHandler: (void (^)(NSError* error)) handler;


/// Send email with with delay or schedule
/// Send an email using a delay. Will place the email onto a scheduler that will then be processed and sent. Use delays to schedule email sending.
///
/// @param inboxId ID of the inbox you want to send the email from
/// @param sendEmailOptions 
/// @param sendAtTimestamp Sending timestamp (optional)
/// @param sendAtNowPlusSeconds Send after n seconds (optional)
/// @param validateBeforeEnqueue Validate before adding to queue (optional)
/// 
///  code:201 message:"Created"
///
/// @return OAIScheduledJobDto*
-(NSURLSessionTask*) sendWithScheduleWithInboxId: (NSString*) inboxId
    sendEmailOptions: (OAISendEmailOptions*) sendEmailOptions
    sendAtTimestamp: (NSDate*) sendAtTimestamp
    sendAtNowPlusSeconds: (NSNumber*) sendAtNowPlusSeconds
    validateBeforeEnqueue: (NSNumber*) validateBeforeEnqueue
    completionHandler: (void (^)(OAIScheduledJobDto* output, NSError* error)) handler;


/// Set inbox favourited state
/// Set and return new favourite state for an inbox
///
/// @param inboxId ID of inbox to set favourite state
/// @param setInboxFavouritedOptions 
/// 
///  code:200 message:"OK"
///
/// @return OAIInboxDto*
-(NSURLSessionTask*) setInboxFavouritedWithInboxId: (NSString*) inboxId
    setInboxFavouritedOptions: (OAISetInboxFavouritedOptions*) setInboxFavouritedOptions
    completionHandler: (void (^)(OAIInboxDto* output, NSError* error)) handler;


/// Update Inbox. Change name and description. Email address is not editable.
/// Update editable fields on an inbox
///
/// @param inboxId 
/// @param updateInboxOptions 
/// 
///  code:200 message:"OK"
///
/// @return OAIInboxDto*
-(NSURLSessionTask*) updateInboxWithInboxId: (NSString*) inboxId
    updateInboxOptions: (OAIUpdateInboxOptions*) updateInboxOptions
    completionHandler: (void (^)(OAIInboxDto* output, NSError* error)) handler;



@end
