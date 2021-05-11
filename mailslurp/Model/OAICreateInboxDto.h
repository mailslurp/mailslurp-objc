#import <Foundation/Foundation.h>
#import "OAIObject.h"

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





@protocol OAICreateInboxDto
@end

@interface OAICreateInboxDto : OAIObject

/* Grant team access to this inbox and the emails that belong to it for team members of your organization. [optional]
 */
@property(nonatomic) NSNumber* allowTeamAccess;
/* Optional description of the inbox for labelling purposes. Is shown in the dashboard and can be used with [optional]
 */
@property(nonatomic) NSString* _description;
/* A custom email address to use with the inbox. Defaults to null. When null MailSlurp will assign a random email address to the inbox such as `123@mailslurp.com`. If you use the `useDomainPool` option when the email address is null it will generate an email address with a more varied domain ending such as `123@mailslurp.info` or `123@mailslurp.biz`. When a custom email address is provided the address is split into a domain and the domain is queried against your user. If you have created the domain in the MailSlurp dashboard and verified it you can use any email address that ends with the domain. Send an email to this address and the inbox will receive and store it for you. To retrieve the email use the Inbox and Email Controller endpoints with the inbox ID. [optional]
 */
@property(nonatomic) NSString* emailAddress;
/* Optional inbox expiration date. If null then this inbox is permanent and the emails in it won't be deleted. If an expiration date is provided or is required by your plan the inbox will be closed when the expiration time is reached. Expired inboxes still contain their emails but can no longer send or receive emails. An ExpiredInboxRecord is created when an inbox and the email address and inbox ID are recorded. The expiresAt property is a timestamp string in ISO DateTime Format yyyy-MM-dd'T'HH:mm:ss.SSSXXX. [optional]
 */
@property(nonatomic) NSDate* expiresAt;
/* Number of milliseconds that inbox should exist for [optional]
 */
@property(nonatomic) NSNumber* expiresIn;
/* Is the inbox favorited. Favouriting inboxes is typically done in the dashboard for quick access or filtering [optional]
 */
@property(nonatomic) NSNumber* favourite;
/* HTTP or SMTP inbox [optional]
 */
@property(nonatomic) NSString* inboxType;
/* Optional name of the inbox. Displayed in the dashboard for easier search [optional]
 */
@property(nonatomic) NSString* name;
/* Tags that inbox has been tagged with. Tags can be added to inboxes to group different inboxes within an account. You can also search for inboxes by tag in the dashboard UI. [optional]
 */
@property(nonatomic) NSArray<NSString*>* tags;
/* Use the MailSlurp domain name pool with this inbox when creating the email address. Defaults to null. If enabled the inbox will be an email address with a domain randomly chosen from a list of the MailSlurp domains. This is useful when the default `@mailslurp.com` email addresses used with inboxes are blocked or considered spam by a provider or receiving service. When domain pool is enabled an email address will be generated ending in `@mailslurp.{world,info,xyz,...}` . This means a TLD is randomly selecting from a list of `.biz`, `.info`, `.xyz` etc to add variance to the generated email addresses. When null or false MailSlurp uses the default behavior of `@mailslurp.com` or custom email address provided by the emailAddress field. [optional]
 */
@property(nonatomic) NSNumber* useDomainPool;

@end
