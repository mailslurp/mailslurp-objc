#import <Foundation/Foundation.h>
#import "OAIObject.h"

/**
* MailSlurp API
* MailSlurp is an API for sending and receiving emails from dynamically allocated email addresses. It's designed for developers and QA teams to test applications, process inbound emails, send templated notifications, attachments, and more.   ## Resources - [Homepage](https://www.mailslurp.com) - Get an [API KEY](https://app.mailslurp.com/sign-up/) - Generated [SDK Clients](https://www.mailslurp.com/docs/) - [Examples](https://github.com/mailslurp/examples) repository 
*
* The version of the OpenAPI document: d1659dc1567a5b62f65d0612107a50aace03e085
* 
*
* NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
* https://openapi-generator.tech
* Do not edit the class manually.
*/


#import "OAISort.h"
@protocol OAISort;
@class OAISort;



@protocol OAIPageable
@end

@interface OAIPageable : OAIObject


@property(nonatomic) NSNumber* offset;

@property(nonatomic) NSNumber* pageNumber;

@property(nonatomic) NSNumber* pageSize;

@property(nonatomic) NSNumber* paged;

@property(nonatomic) OAISort* sort;

@property(nonatomic) NSNumber* unpaged;

@end
