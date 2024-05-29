# Documentation of Network protocol of "Avant cyclades"

## Type

Clock
	     R
1      ______
       |    |
    W  |    |  W
0 _____|    |____

The Type is configured to run from left to right.
Gives the time to all network cards, to write and read.


## BUS structure to Network protocol.

```
BUS   Start     Dest      Emet      Lendata      data      Check
    |_______| |______|  |______|  |_________|  |______|  |_______|
     1 bit     4 octets  4 octets   4 octets    len data  4 octets
```

 - `Start`   : this is the first bit to send to signal the arrival of transmition.
 - `Dest`    : this is the desired recipient hashed,the mac address of the adresse hashed into 4 bytes.
 - `Emet`    : this is the desired sender hashed, the mac address of hashed into 4 bytes.
 - `Lendata` : this is the length of the data hashed into 4 bytes.
 - `data`    : this is the message.

## Network card

the network card functions in two different parts independent of each other.
```
 the components
- ` Check ` : is by default false. it is the signal saying that the message stops and at the same time indicates the arrival of the new message.
- ` Check ` : the data_output2_left.
- ` Check ` : the data_output2_right.
- ` Check ` : the data_intput2_left.
- ` Check ` : the data_intput2_right.

- ` data 1` : the data_output1_left.
- ` data 1` : the data_intput1_left.

- ` data 2` : the data_output1_right.
- ` data 2` : the data_input1_right.

- ` data 3` : the data_output3_right.
- ` data 3` : the data_intput3_right.

- ` data 4` : the data_output3_left.
- ` data 4` : the data_output3_letf.
    Part left  |  Part right
       ________|_________
       |       |        |
 Check |       |        | Check
------>|       |        |------>
       |       |        |
Data 1 |       |        | Data 2
------>|       |        |------>
       |       |        |
Data 4 |       |        | Data 3
<------|       |        |<------
       |       |        |
       |_______|________|
               |
```
