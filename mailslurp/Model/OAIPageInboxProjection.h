#import <Foundation/Foundation.h>
#import "OAIObject.h"

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


#import "OAIInboxPreview.h"
#import "OAIPageableObject.h"
#import "OAISort.h"
@protocol OAIInboxPreview;
@class OAIInboxPreview;
@protocol OAIPageableObject;
@class OAIPageableObject;
@protocol OAISort;
@class OAISort;



@protocol OAIPageInboxProjection
@end

@interface OAIPageInboxProjection : OAIObject


@property(nonatomic) NSArray<OAIInboxPreview>* content;

@property(nonatomic) OAIPageableObject* pageable;

@property(nonatomic) NSNumber* total;

@property(nonatomic) NSNumber* last;

@property(nonatomic) NSNumber* totalElements;

@property(nonatomic) NSNumber* totalPages;

@property(nonatomic) NSNumber* size;

@property(nonatomic) NSNumber* number;

@property(nonatomic) OAISort* sort;

@property(nonatomic) NSNumber* first;

@property(nonatomic) NSNumber* numberOfElements;

@property(nonatomic) NSNumber* empty;

@end
