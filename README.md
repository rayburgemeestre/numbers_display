## Files

- `numbers_display.ino` - The source file for the clock, flash this to the
  Wemos D1 mini.
- `digits` - Directory containing scripts for customizing the digits. 

## Caveats

In Arduino Studio I recall I had to use "Wemos D1 R mini" or something similar.
However that device is no longer available, now I have to use "LOLIN WEMOS R1
R2 & mini". Really be careful not to use the wrong device, I have spent
countless hours debugging an issue that was simply due to the wrong pins being
assigned, and for example RX and TX were repurposed for something else.
