@@
Entity e;
Entity *ep;
struct Entity *sep;
@@
(
-   e.axObj.info
+   GetEntInfo(&e)
|
-   ep->axObj.info
+   GetEntInfo(ep)
|
-   sep->axObj.info
+   GetEntInfo(sep)
)
@@
Entity e;
@@
(
- GetEntInfo(&e)
+ *GetEntInfo(&e)
)
  = ...;
