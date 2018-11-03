Mention UART mode, Any type & brand is supported.

resolution .001
accuracy +/– 0.002
range .001 − 14.000
operating voltage 3.3V − 5V

1. Example uses software serial only for sending

2. SerialEvent occurs whenever a new data comes in the hardware serial RX.

3. Connect VCC on EZO circuit to 5V pin on wemos and GND to GND pin on wemos.

4. Connect RX on EZO circuit to hardware RX pin on wemos.

5. Connect TX on EZO circuit to D7 on wemos (GPIO 13).

6. Enter serial monitor:

``
pio device monitor --eol CR
```

7. By default, continuous read mode every 1s which should be outputted to the console.

8. Enter commands (e.g. type "i" and then hit return).

Output should be:

```
?I,pH,2.12
*OK
```

9. To calibrate using three points:

Check temperature (default 25)

T,?
?T,25.00 <cr>
*OK <cr>

Set the right temperature:
T,19.5

Put probe in mid solution (pH 7)
Let it stabilize for 1 or 2 minutes
Enter "Cal,mid,7.00"

Put probe in low solution (pH 4)
Let it stabilize for 1 or 2 minutes
Enter "Cal,low,4.00"

Put probe in low solution (pH 10)
Let it stabilize for 1 or 2 minutes
Enter "Cal,high,10.00"

Enter command: Export,?

Result
?EXPORT,4,46
*OK

This means 4 strings of up to 12 chars long
Export
00EF44593CC3
*OK
Export
C040C3010101
*OK
Export
00804000E040
*OK
Export
00204117E4
*OK
Export
*OK
*DONE
