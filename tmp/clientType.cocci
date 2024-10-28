@@
EntityInfo *e;
@@
(
- e->clientType == 1
+ e->clientType == CLIENT_TYPE_CLIENT
|
- e->clientType != 1
+ e->clientType != CLIENT_TYPE_CLIENT
|
- e->clientType == 2
+ e->clientType == CLIENT_TYPE_PARTNER
|
- e->clientType != 2
+ e->clientType != CLIENT_TYPE_PARTNER
|
- e->clientType == 4
+ e->clientType == CLIENT_TYPE_DONT_MOVE
|
- e->clientType != 4
+ e->clientType != CLIENT_TYPE_DONT_MOVE
)
