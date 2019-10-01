# HRS3300-Arduino-Library
Arduino Library for the HRS3300 Heartrate sensor for the nRF52 Bluetooth Micro


It includes a closed source .a file, to get the Arduino IDE recognize it you need to edit the Platform.txt from the nRF52 library.


Add: ```compiler.libraries.ldflags=``` somewhere as a new line.

also add: ```{compiler.libraries.ldflags}``` somewhere ad the end of line ```compine.pattern```

For more infos watch this video for another Heartrate Sensor: 
[![YoutubeVideo](https://img.youtube.com/vi/E0W65KbaeA8/0.jpg)](https://www.youtube.com/watch?v=E0W65KbaeA8)
