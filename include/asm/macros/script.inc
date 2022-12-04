.macro warpLocation id:req
    .byte 0x01
    .byte 0x00
    .2byte \id
    .4byte 0x00, 0x00, 0x00
.endm

.macro warpDungeon id:req
    .byte 0x02
    .byte 0x00
    .2byte \id
    .4byte 0x00, 0x00, 0x00
.endm

.macro warpFriendArea time:req
    .byte 0x02
    .byte 0x00
    .2byte \time
    .4byte 0x00, 0x00, 0x00
.endm

.macro ConfirmDungeonRules
    .byte 0x05
    .4byte 0x00, 0x00, 0x00
    .byte 0x00, 0x00, 0x00
.endm

.macro changeTileset id:req
    .byte 0x08, 0x00, 0x00, 0x00
    .2byte \id
    .4byte 0x00, 0x00
    .2byte 0x00
.endm

@ Start Scene? Run Call?
.macro StartSceneRunCall id:req
    .byte 0x0C
    .byte \id
    .byte 0xFF, 0xFF
    .4byte 0x00, 0x00, 0x00
.endm

.macro RunCall id:req
    .byte 0x0D
    .byte \id
    .byte 0xFF, 0xFF
    .4byte 0x00, 0x00, 0x00
.endm

.macro triggerCutscene id:req
    .byte 0x1B
    .byte 0x00
    .2byte \id
    .4byte 0x00, 0x00, 0x00
.endm

.macro fadeOut arg0:req time:req arg2:req
    .byte 0x23
    .byte \arg0
    .2byte \time
    .4byte \arg2
    .4byte 0x00, 0x00
.endm

.macro fadeColorOut arg0:req arg1:req time:req color:req
    .byte 0x27
    .byte \arg0
    .2byte \arg1
    .4byte \time
    .4byte \color
    .4byte 0x00
.endm

.macro fadeColorIn arg0:req arg1:req time:req color:req
    .byte 0x28
    .byte \arg0
    .2byte \arg1
    .4byte \time
    .4byte \color
    .4byte 0x00
.endm

.macro loadData type:req charac:req source:req
    .byte 0x2D
    .byte \type
    .2byte \charac
    .2byte \source
    .4byte 0x00, 0x00
    .2byte 0x00
.endm

@ Face Locations
.set bottomL, 0x2
.set bottomR, 0x3
.set insetTopL, 0xE
.set insetTopR, 0xF

.set previousLoc, 0x15

.macro selectFace loc:req charac:req face:req
    .byte 0x2E
    .byte \loc
    .2byte \charac
    .4byte \face
    .4byte 0x00, 0x00
.endm

.macro closeTextBox
    .byte 0x30
    .4byte 0x00, 0x00, 0x00
    .byte 0x00, 0x00, 0x00
.endm

.macro scrollTextBox character:req textPtr:req
    .byte 0x33, 0x00
    .2byte \character
    .4byte 0x00, 0x00
    .4byte \textPtr
.endm

.macro PicNameTextBox character:req textPtr:req
    .byte 0x34, 0x00
    .2byte \character
    .4byte 0x00, 0x00
    .4byte \textPtr
.endm

.macro quickCloseTextBox character:req textPtr:req
    .byte 0x36, 0x00
    .2byte \character
    .4byte 0x00, 0x00
    .4byte \textPtr
.endm

@ Is it always 0xff, 0xff?
.macro floatingText textPtr:req
    .byte 0x37, 0x00
    .byte 0xff, 0xff
    .4byte 0x00, 0x00
    .4byte \textPtr
.endm

.macro fadeFloatingText time:req textPtr:req
    .byte 0x39, 0x00
    .2byte \time
    .4byte 0x00, 0x00
    .4byte \textPtr
.endm

.macro YesNoTextBox eventID:req character:req textPtr:req
    .byte 0x3A, 0x00
    .2byte \eventID
    .2byte \character
    .2byte 0x00
    .4byte 0x00
    .4byte \textPtr
.endm

.macro showName arg0:req
    .byte 0x3B
    .byte \arg0
    .2byte 0x00
    .4byte 0x00, 0x00, 0x00
.endm

@ TODO: 0x3C has a lot of different cases...

.macro renamePoke id:req
    .byte 0x3D, 0x00, 0x00, 0x00
    .byte \id, 0x00, 0x00, 0x00
    .4byte 0x00, 0x00
.endm

.macro renameTeam
    .byte 0x3e, 0x00, 0x00, 0x00
    .4byte 0x00, 0x00, 0x00
.endm

.macro abruptStopMusic
    .byte 0x42
    .4byte 0x00, 0x00, 0x00
    .byte 0x00, 0x00, 0x00
.endm

.macro fadeMusic time:req
    .byte 0x43
    .byte 0x00
    .2byte \time
    .4byte 0x00, 0x00, 0x00
.endm

.macro PlayMusic id:req
    .byte 0x44
    .byte 0x00
    .2byte 0x0
    .2byte \id
    .2byte 0x00
    .4byte 0x00, 0x00
.endm

.macro fadeInMusic id:req time:req
    .byte 0x45, 0x00
    .2byte \id
    .2byte \time
    .4byte 0x00, 0x00
    .2byte 0x00
.endm

@ Also seen referred to as StopSng
.macro pushR14
    .byte 0x47
    .4byte 0x00, 0x00, 0x00
    .byte 0x00, 0x00, 0x00
.endm

.macro fadeMusicOut time:req
    .byte 0x48
    .byte 0x00
    .2byte \time
    .4byte 0x00, 0x00, 0x00
.endm

.macro playSound id:req
    .byte 0x4C
    .byte 0x00, 0x00, 0x00
    .2byte \id
    .4byte 0x00, 0x00
    .2byte 0x00
.endm

.macro stopSound id:req
    .byte 0x4D
    .byte 0x00, 0x00, 0x00
    .2byte \id
    .4byte 0x00, 0x00
    .2byte 0x00
.endm

.macro setAnimation anim:req
    .byte 0x54
    .byte 0x00
    .2byte \anim
    .4byte 0x00, 0x00, 0x00
.endm

.macro warpToLoc id:req
    .byte 0x5B, 0x00
    .2byte 0x00
    .byte \id
    .byte 0x00, 0x00, 0x00
    .4byte 0x00, 0x00
.endm

@ move to prefined location along grid
.macro gridMoveTo speed:req id:req
    .byte 0x6B, 0x00
    .2byte \speed
    .byte \id
    .4byte 0x00, 0x00
    .byte 0x00, 0x00, 0x00
.endm

.macro changeSpriteZ speed:req targetHeight:req
    .byte 0x70, 0x00
    .byte \speed
    .3byte \targetHeight
    .4byte 0x00, 0x00
    .2byte 0x00
.endm

@ Rotation Directions
.set CW, 1
.set CCW, 2
.set shortestDir, 0xA

@ Cardinal Directions / Facing Directions
.set south,      0
.set southeast,  1
.set east,       2
.set northeast,  3
.set north,      4
.set northwest,  5
.set west,       6
.set southwest,  7

.macro setFaceDir delay:req faceDir:req
    .byte 0x8B
    .byte \delay
    .byte \faceDir
    .byte 0x00
    .4byte 0x00, 0x00, 0x00
.endm

.macro rotate time:req rotDir:req faceDir:req
    .byte 0x91
    .byte \time
    .byte \rotDir
    .byte 0x00
    .byte \faceDir
    .byte 0x00
    .4byte 0x00, 0x00
    .2byte 0x00
.endm

.macro initVariableTextBox arg0:req arg1:req speaker:req
    .byte 0xCF
    .byte \arg0
    .byte \arg1
    .byte 0x00
    .4byte \speaker
    .4byte 0x00, 0x00
.endm

.macro variableTextBox version:req textPtr:req
    .byte 0xD0, 0x00
    .2byte \version
    .4byte 0x00, 0x00
    .4byte \textPtr
.endm

.macro elseTextBox textPtr:req
    .byte 0xD1, 0x00
    .4byte 0x00, 0x00
    .byte 0x00, 0x00
    .4byte \textPtr
.endm

.macro pause time:req
    .byte 0xDB
    .byte 0x00
    .2byte \time
    .4byte 0x00, 0x00, 0x00
.endm

@ Wait for sound to finish playing?
.macro waitSound id:req
    .byte 0xE2
    .byte 0x00
    .2byte \id
    .4byte 0x00, 0x00, 0x00
.endm

.macro waitFlag flagnum:req
    .byte 0xE3
    .byte 0x00
    .2byte \flagnum
    .4byte 0x00, 0x00, 0x00
.endm

.macro setFlag flagnum:req
    .byte 0xE4
    .byte 0x00
    .2byte \flagnum
    .4byte 0x00, 0x00, 0x00
.endm

.macro goTo id:req
    .byte 0xE5
    .byte 0x00
    .byte \id
    .byte 0x00
    .4byte 0x00, 0x00, 0x00
.endm

@ Loop at label until end of scene
.macro loopLabel id:req
    .byte 0xE7, 0x00
    .byte \id, 0x00
    .4byte 0x00, 0x00, 0x00
.endm

.macro executeScript scriptNum:req
    .byte 0xE8
    .byte 0x00
    .2byte \scriptNum
    .4byte 0x00, 0x00, 0x00
.endm

.macro MsgEnd arg0:req
    .byte 0xE9
    .byte 0x00
    .2byte \arg0
    .4byte 0x00, 0x00, 0x00
.endm

.macro endFuncContinueScript
    .byte 0xEE
    .4byte 0x00, 0x00, 0x00
    .byte 0x00, 0x00, 0x00
.endm

.macro endFuncandScript
    .byte 0xEF
    .4byte 0x00, 0x00, 0x00
    .byte 0x00, 0x00, 0x00
.endm

.macro closeThread
    .byte 0xF0
    .4byte 0x00, 0x00, 0x00
    .byte 0x00, 0x00, 0x00
.endm

.macro closeThreadRemoveObject
    .byte 0xF1
    .4byte 0x00, 0x00, 0x00
    .byte 0x00, 0x00, 0x00
.endm

@ Set label for loop
.macro label id:req
    .byte 0xF4, 0x00
    .byte \id, 0x00
    .4byte 0x00, 0x00, 0x00
.endm
