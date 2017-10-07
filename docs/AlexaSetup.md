
Setting up Opengarage as an Alexa Compatible Smart Lock
=======

This walks you through setting up Opengarage as an Alexa home skill using the smart lock capability. Alexa APIs don't currently support a native skill for doors so a lock is the closest option. Alexa doesn't currently support unlocking so this provides status and lock/shut only. You do need to use the term lock and unlock instead of open/shut but you learn that quickly enough.

Allows you to ask
* "Alexa is the Garage Door Unlocked/Locked?"
* "Alexa Lock the Garage Door."
* "Alexa Unlock the Garage Door." (not supported yet)

High Level Request Flow
=======
You query status or give command to Alexa -> Alexa recognizes the devicename and forwards to a node-red bridge service  -> Node-red on your internal network picks this up via outgoing connection -> Makes Request to OpenGarage and get response -> Node red sends response to Bridge service -> Sends back to Alexa -> Response to user.

High Level Steps
=======
* Setup an account on the node-red home skill bridge service
* Setup a Smart Lock in the service
* Register the node-red home skill for your alexa
* Install Node-red on your home network (I use a $10 Raspberry Pi Zero Wireless)
* Setup a Simple Node-Red flow to talk to both the bridge service and your opengarage

Step 1: Setup an Account on the bridge web service site
========

Go here  https://alexa-node-red.bm.hardill.me.uk/
Technically this would allow the owner of this site or anyone that has access to it to send a request as if they are Alexa but at least for my house there are easier ways to break in so I don't stress about it. I believe he has the code on github if you want to host your own service. I'm not sure why, but neither Ifft or Blynk have added similiar capabiliies.

Step 2: Create a Lock Device
========

Setup a device in the bridge that has both lock options enabled. Don't pick anything else or your device won't work correctly
The name you pick here is what you will call the device to Alexa, so Garage Door, Left Garage Door, Open Garage whatever


<img src="/Screenshots/DeviceSetup.PNG" height=200> 


Step 3: In the Alexa app add the related skill Node-Red by Ben Hardill
========

Once complete, Ask Alexa to Discover Devices,  the count it should report should have incremented (not sure why Alexa doesn't tell you the name of the devices it found..) You should also be able to now ask, "Alexa is [Name] Unlocked?" At this point it will say device not responding

Step 4: Setup the Node-Red flow to handle status query and shut commands
========

On your device (I use a pi zero w) install or update Node-Red (its built in to Raspbian but out of date)
Update via the instructions here 
https://nodered.org/docs/hardware/raspberrypi. Then install the node node-red-contrib-alexa-home-skill using the Manage Palette option in the uppper right menu. When Complete reboot your device so everthing registers

Step 5: Setup a flow
=======
Example Flow with details of each node
<img src="/Screenshots/Node-RedFlow.PNG"> 


GarageDoor
========
Alexa Home Node (incoming from the service)
Enter your account details and pick your defined device


<img src="/Screenshots/AlexaHomeNode.PNG" height=200> 




Query or Change
========
Switch Node that determines if you asked Alexa for status or to shut the door


<img src="/Screenshots/SwitchNode.PNG" height=200> 




Query OG Status
========
HTTP Request Node. Insert your device name/IP address


<img src="/Screenshots/QueryOGStatusNode.PNG" height=200> 




Build Alexa Response
========
Function Node. This converts the OpenGarage data into the correct format for Alexa


<img src="/Screenshots/BuildAlexaResponseNode.PNG" height=200> 




Alexa Home Response
========
Alexa Home Response Node. No customization - this just replies to Alexa (No Screenshot)




Lock or Unlock
========
Switch Node - Detemines if the request was to Lock(Shut) or Unlock(Open)


<img src="/Screenshots/LockOrUnlockNode.PNG" height=200> 



Shut Door
========
HTTP Request - Sends Shut Command to OpenGarage. Note: This is customized for my firmware where there are discrete shut and open commands that only apply if applicable. If using out of the box you need to send Click=1 instead of close=1


<img src="/Screenshots/CloseDoorNode.PNG" height=200> 


Parse Lock Request
========
Function - Takes the response from OpenGarage and formats it for Alexa. Note: This really only tells you if OG got the request - the timing doesn't currenly allow actual validation the door changed state (Amazon just added this but the bridge service doesn't support it yet)


<img src="/Screenshots/ParseLockResponseNode.PNG" height=200> 


Delay 5s
========
This makes the service seem like it actually shuts the door before responding locked


<img src="/Screenshots/Delay5sNode.PNG" height=200> 




