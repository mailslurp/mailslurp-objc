#import <Foundation/Foundation.h>
#import "OAIAttachmentMetaData.h"
#import "OAIContentMatchOptions.h"
#import "OAIDownloadAttachmentDto.h"
#import "OAIEmail.h"
#import "OAIEmailContentMatchResult.h"
#import "OAIEmailTextLinesResult.h"
#import "OAIForwardEmailOptions.h"
#import "OAIPageEmailProjection.h"
#import "OAIRawEmailJson.h"
#import "OAIReplyToEmailOptions.h"
#import "OAISentEmailDto.h"
#import "OAIUnreadCount.h"
#import "OAIValidationDto.h"
#import "OAIApi.h"

/**
* MailSlurp API
* MailSlurp is an API for sending and receiving emails from dynamically allocated email addresses. It's designed for developers and QA teams to test applications, process inbound emails, send templated notifications, attachments, and more.  ## Resources  - [Homepage](https://www.mailslurp.com) - Get an [API KEY](https://app.mailslurp.com/sign-up/) - Generated [SDK Clients](https://www.mailslurp.com/docs/) - [Examples](https://github.com/mailslurp/examples) repository 
*
* The version of the OpenAPI document: 6.5.2
* 
*
* NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
* https://openapi-generator.tech
* Do not edit the class manually.
*/



@interface OAIEmailControllerApi: NSObject <OAIApi>

extern NSString* kOAIEmailControllerApiErrorDomain;
extern NSInteger kOAIEmailControllerApiMissingParamErrorCode;

-(instancetype) initWithApiClient:(OAIApiClient *)apiClient NS_DESIGNATED_INITIALIZER;

/// Delete all emails in all inboxes.
/// Deletes all emails in your account. Be careful as emails cannot be recovered
///
/// 
///  code:204 message:"No Content",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden"
///
/// @return void
-(NSURLSessionTask*) deleteAllEmailsWithCompletionHandler: 
    (void (^)(NSError* error)) handler;


/// Delete an email
/// Deletes an email and removes it from the inbox. Deleted emails cannot be recovered.
///
/// @param emailId ID of email to delete
/// 
///  code:204 message:"No Content",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden"
///
/// @return void
-(NSURLSessionTask*) deleteEmailWithEmailId: (NSString*) emailId
    completionHandler: (void (^)(NSError* error)) handler;


/// Get email attachment bytes. Returned as `octet-stream` with content type header. If you have trouble with byte responses try the `downloadAttachmentBase64` response endpoints and convert the base 64 encoded content to a file or string.
/// Returns the specified attachment for a given email as a stream / array of bytes. You can find attachment ids in email responses endpoint responses. The response type is application/octet-stream.
///
/// @param attachmentId ID of attachment
/// @param emailId ID of email
/// @param apiKey Can pass apiKey in url for this request if you wish to download the file in a browser. Content type will be set to original content type of the attachment file. This is so that browsers can download the file correctly. (optional)
/// 
///  code:200 message:"OK",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return NSData*
-(NSURLSessionTask*) downloadAttachmentWithAttachmentId: (NSString*) attachmentId
    emailId: (NSString*) emailId
    apiKey: (NSString*) apiKey
    completionHandler: (void (^)(NSData* output, NSError* error)) handler;


/// Get email attachment as base64 encoded string alternative to binary responses. Decode the `base64FileContents` as a `utf-8` encoded string or array of bytes depending on the `contentType`.
/// Returns the specified attachment for a given email as a base 64 encoded string. The response type is application/json. This method is similar to the `downloadAttachment` method but allows some clients to get around issues with binary responses.
///
/// @param attachmentId ID of attachment
/// @param emailId ID of email
/// 
///  code:200 message:"OK",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return OAIDownloadAttachmentDto*
-(NSURLSessionTask*) downloadAttachmentBase64WithAttachmentId: (NSString*) attachmentId
    emailId: (NSString*) emailId
    completionHandler: (void (^)(OAIDownloadAttachmentDto* output, NSError* error)) handler;


/// Get email body as string. Returned as `plain/text` with content type header.
/// Returns the specified email body for a given email as a string
///
/// @param emailId ID of email
/// 
///  code:200 message:"OK",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return NSString*
-(NSURLSessionTask*) downloadBodyWithEmailId: (NSString*) emailId
    completionHandler: (void (^)(NSString* output, NSError* error)) handler;


/// Get email body in bytes. Returned as `octet-stream` with content type header.
/// Returns the specified email body for a given email as a stream / array of bytes.
///
/// @param emailId ID of email
/// 
///  code:200 message:"OK",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return NSData*
-(NSURLSessionTask*) downloadBodyBytesWithEmailId: (NSString*) emailId
    completionHandler: (void (^)(NSData* output, NSError* error)) handler;


/// Forward email to recipients
/// Forward an existing email to new recipients.
///
/// @param emailId ID of email
/// @param forwardEmailOptions forwardEmailOptions
/// 
///  code:201 message:"Created",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return void
-(NSURLSessionTask*) forwardEmailWithEmailId: (NSString*) emailId
    forwardEmailOptions: (OAIForwardEmailOptions*) forwardEmailOptions
    completionHandler: (void (^)(NSError* error)) handler;


/// Get email attachment metadata. This is the `contentType` and `contentLength` of an attachment. To get the individual attachments  use the `downloadAttachment` methods.
/// Returns the metadata such as name and content-type for a given attachment and email.
///
/// @param attachmentId ID of attachment
/// @param emailId ID of email
/// 
///  code:200 message:"OK",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return OAIAttachmentMetaData*
-(NSURLSessionTask*) getAttachmentMetaDataWithAttachmentId: (NSString*) attachmentId
    emailId: (NSString*) emailId
    completionHandler: (void (^)(OAIAttachmentMetaData* output, NSError* error)) handler;


/// Get all email attachment metadata. Metadata includes name and attachment size.
/// Returns an array of attachment metadata such as name and content-type for a given email if present.
///
/// @param emailId ID of email
/// 
///  code:200 message:"OK",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return NSArray<OAIAttachmentMetaData>*
-(NSURLSessionTask*) getAttachments1WithEmailId: (NSString*) emailId
    completionHandler: (void (^)(NSArray<OAIAttachmentMetaData>* output, NSError* error)) handler;


/// Get email content including headers and body. Expects email to exist by ID. For emails that may not have arrived yet use the WaitForController.
/// Returns a email summary object with headers and content. To retrieve the raw unparsed email use the getRawEmail endpoints
///
/// @param emailId emailId
/// @param decode Decode email body quoted-printable encoding to plain text. SMTP servers often encode text using quoted-printable format (for instance &#x60;&#x3D;D7&#x60;). This can be a pain for testing (optional) (default to @(NO))
/// 
///  code:200 message:"OK",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return OAIEmail*
-(NSURLSessionTask*) getEmailWithEmailId: (NSString*) emailId
    decode: (NSNumber*) decode
    completionHandler: (void (^)(OAIEmail* output, NSError* error)) handler;


/// Get email content regex pattern match results. Runs regex against email body and returns match groups.
/// Return the matches for a given Java style regex pattern. Do not include the typical `/` at start or end of regex in some languages. Given an example `your code is: 12345` the pattern to extract match looks like `code is: (\\d{6})`. This will return an array of matches with the first matching the entire pattern and the subsequent matching the groups: `['code is: 123456', '123456']` See https://docs.oracle.com/javase/8/docs/api/java/util/regex/Pattern.html for more information of available patterns. 
///
/// @param emailId ID of email to match against
/// @param contentMatchOptions contentMatchOptions
/// 
///  code:200 message:"OK",
///  code:201 message:"Created",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return OAIEmailContentMatchResult*
-(NSURLSessionTask*) getEmailContentMatchWithEmailId: (NSString*) emailId
    contentMatchOptions: (OAIContentMatchOptions*) contentMatchOptions
    completionHandler: (void (^)(OAIEmailContentMatchResult* output, NSError* error)) handler;


/// Get email content as HTML. For displaying emails in browser context.
/// Retrieve email content as HTML response for viewing in browsers. Decodes quoted-printable entities and converts charset to UTF-8. Pass your API KEY as a request parameter when viewing in a browser: `?apiKey=xxx`
///
/// @param emailId emailId
/// @param decode decode (optional) (default to @(NO))
/// 
///  code:200 message:"OK",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return NSString*
-(NSURLSessionTask*) getEmailHTMLWithEmailId: (NSString*) emailId
    decode: (NSNumber*) decode
    completionHandler: (void (^)(NSString* output, NSError* error)) handler;


/// Parse and return text from an email, stripping HTML and decoding encoded characters
/// Parse an email body and return the content as an array of text. HTML parsing uses JSoup which supports JQuery/CSS style selectors
///
/// @param emailId ID of email to perform HTML query on
/// @param htmlSelector HTML selector to search for. Uses JQuery/JSoup/CSS style selector like &#39;.my-div&#39; to match content. See https://jsoup.org/apidocs/org/jsoup/select/Selector.html for more information. (optional)
/// 
///  code:200 message:"OK",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return OAIEmailTextLinesResult*
-(NSURLSessionTask*) getEmailHTMLQueryWithEmailId: (NSString*) emailId
    htmlSelector: (NSString*) htmlSelector
    completionHandler: (void (^)(OAIEmailTextLinesResult* output, NSError* error)) handler;


/// Parse and return text from an email, stripping HTML and decoding encoded characters
/// Parse an email body and return the content as an array of strings. HTML parsing uses JSoup and UNIX line separators.
///
/// @param emailId ID of email to fetch text for
/// @param decodeHtmlEntities Decode HTML entities (optional)
/// @param lineSeparator Line separator character (optional)
/// 
///  code:200 message:"OK",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return OAIEmailTextLinesResult*
-(NSURLSessionTask*) getEmailTextLinesWithEmailId: (NSString*) emailId
    decodeHtmlEntities: (NSNumber*) decodeHtmlEntities
    lineSeparator: (NSString*) lineSeparator
    completionHandler: (void (^)(OAIEmailTextLinesResult* output, NSError* error)) handler;


/// Get all emails in all inboxes. Email API list all.
/// By default returns all emails across all inboxes sorted by ascending created at date. Responses are paginated. You can restrict results to a list of inbox IDs. You can also filter out read messages
///
/// @param inboxId Optional inbox ids to filter by. Can be repeated. By default will use all inboxes belonging to your account. (optional)
/// @param page Optional page index in email list pagination (optional) (default to @0)
/// @param size Optional page size in email list pagination. Maximum size is 100. Use page index and sort to page through larger results (optional) (default to @20)
/// @param sort Optional createdAt sort direction ASC or DESC (optional) (default to @"ASC")
/// @param unreadOnly Optional filter for unread emails only. All emails are considered unread until they are viewed in the dashboard or requested directly (optional) (default to @(NO))
/// 
///  code:200 message:"OK",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return OAIPageEmailProjection*
-(NSURLSessionTask*) getEmailsPaginatedWithInboxId: (NSArray<NSString*>*) inboxId
    page: (NSNumber*) page
    size: (NSNumber*) size
    sort: (NSString*) sort
    unreadOnly: (NSNumber*) unreadOnly
    completionHandler: (void (^)(OAIPageEmailProjection* output, NSError* error)) handler;


/// Get latest email in all inboxes. Most recently received.
/// Get the newest email in all inboxes or in a passed set of inbox IDs
///
/// @param inboxIds Optional set of inboxes to filter by. Only get the latest email from these inbox IDs (optional)
/// 
///  code:200 message:"OK",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return OAIEmail*
-(NSURLSessionTask*) getLatestEmailWithInboxIds: (NSArray<NSString*>*) inboxIds
    completionHandler: (void (^)(OAIEmail* output, NSError* error)) handler;


/// Get latest email in an inbox. Use `WaitForController` to get emails that may not have arrived yet.
/// Get the newest email in all inboxes or in a passed set of inbox IDs
///
/// @param inboxId ID of the inbox you want to get the latest email from (optional)
/// 
///  code:200 message:"OK",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return OAIEmail*
-(NSURLSessionTask*) getLatestEmailInInboxWithInboxId: (NSString*) inboxId
    completionHandler: (void (^)(OAIEmail* output, NSError* error)) handler;


/// Get all organization emails. List team or shared test email accounts
/// By default returns all emails across all team inboxes sorted by ascending created at date. Responses are paginated. You can restrict results to a list of inbox IDs. You can also filter out read messages
///
/// @param inboxId Optional inbox ids to filter by. Can be repeated. By default will use all inboxes belonging to your account. (optional)
/// @param page Optional page index in email list pagination (optional) (default to @0)
/// @param size Optional page size in email list pagination. Maximum size is 100. Use page index and sort to page through larger results (optional) (default to @20)
/// @param sort Optional createdAt sort direction ASC or DESC (optional) (default to @"ASC")
/// @param unreadOnly Optional filter for unread emails only. All emails are considered unread until they are viewed in the dashboard or requested directly (optional) (default to @(NO))
/// 
///  code:200 message:"OK",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return OAIPageEmailProjection*
-(NSURLSessionTask*) getOrganizationEmailsPaginatedWithInboxId: (NSArray<NSString*>*) inboxId
    page: (NSNumber*) page
    size: (NSNumber*) size
    sort: (NSString*) sort
    unreadOnly: (NSNumber*) unreadOnly
    completionHandler: (void (^)(OAIPageEmailProjection* output, NSError* error)) handler;


/// Get raw email string. Returns unparsed raw SMTP message with headers and body.
/// Returns a raw, unparsed, and unprocessed email. If your client has issues processing the response it is likely due to the response content-type which is text/plain. If you need a JSON response content-type use the getRawEmailJson endpoint
///
/// @param emailId ID of email
/// 
///  code:200 message:"text/plain raw email",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return NSString*
-(NSURLSessionTask*) getRawEmailContentsWithEmailId: (NSString*) emailId
    completionHandler: (void (^)(NSString* output, NSError* error)) handler;


/// Get raw email in JSON. Unparsed SMTP message in JSON wrapper format.
/// Returns a raw, unparsed, and unprocessed email wrapped in a JSON response object for easier handling when compared with the getRawEmail text/plain response
///
/// @param emailId ID of email
/// 
///  code:200 message:"OK",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return OAIRawEmailJson*
-(NSURLSessionTask*) getRawEmailJsonWithEmailId: (NSString*) emailId
    completionHandler: (void (^)(OAIRawEmailJson* output, NSError* error)) handler;


/// Get unread email count
/// Get number of emails unread. Unread means has not been viewed in dashboard or returned in an email API response
///
/// 
///  code:200 message:"OK",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return OAIUnreadCount*
-(NSURLSessionTask*) getUnreadEmailCountWithCompletionHandler: 
    (void (^)(OAIUnreadCount* output, NSError* error)) handler;


/// Reply to an email
/// Send the reply to the email sender or reply-to and include same subject cc bcc etc. Reply to an email and the contents will be sent with the existing subject to the emails `to`, `cc`, and `bcc`.
///
/// @param emailId ID of the email that should be replied to
/// @param replyToEmailOptions replyToEmailOptions
/// 
///  code:200 message:"OK",
///  code:201 message:"Created",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return OAISentEmailDto*
-(NSURLSessionTask*) replyToEmailWithEmailId: (NSString*) emailId
    replyToEmailOptions: (OAIReplyToEmailOptions*) replyToEmailOptions
    completionHandler: (void (^)(OAISentEmailDto* output, NSError* error)) handler;


/// Validate email HTML contents
/// Validate the HTML content of email if HTML is found. Considered valid if no HTML.
///
/// @param emailId ID of email
/// 
///  code:201 message:"Created",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return OAIValidationDto*
-(NSURLSessionTask*) validateEmailWithEmailId: (NSString*) emailId
    completionHandler: (void (^)(OAIValidationDto* output, NSError* error)) handler;



@end
