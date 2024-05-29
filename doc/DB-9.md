# DB-9
## componants
TOP
- `GND` :   -       Système ground.
- `DTR` :   OUT     Data Terminal Ready Signal.
- `TXD` :   OUT     Transmit Data Signal.
- `RXD` :   IN      Receive Data Signal.
- `CD`  :   IN      Carrier Detect Input Signal.

BOT
- `RI`  :   IN      Ring Indicator Signal.
- `CTS` :   IN      Clear to Send Signal.
- `RTS` :   OUT     Request to Send Signal.
- `DSR` :   IN      Data Set Ready Signal.

## Schema
```
    _______________________________________________
    |          __________                         |
     \  GND DTR| ____TXD|          RXD      CD   /
      \  |  RI    | CTS |       RTS  |  DSR  |  /
       \_|__|_____|_|___|_______|___|____|__|__/
         |  |     | |   |       |   |    |  |
    _____|__|_____|_|___|_______|___|____|__|_____
    |    |  |     | |   |       |   |    |  |    |
     \  GND | DTR_| |  TXD      |   RXD  |  CD  /
      \    RI       CTS        RTS      DSR    /
       \______________________________________/
```
