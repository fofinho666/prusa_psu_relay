# Prusa PSU Relay

The code for a **Seeeduino XIAO** connected to a Relay and a python script to send it commands by serial.

The goal of this is to turn On and Off a printer by using the OctoPrint's [PSU Control plugin](https://plugins.octoprint.org/plugins/psucontrol/).

## Setup
### Seeeduino XIAO
To flash the code, you need the **Arduino IDE** and the **XIAO** board added to it. For that please check this [tutorial](https://wiki.seeedstudio.com/Seeeduino-XIAO/#software).

Don't forget to check if the pin connected the Relay is the same as the `const int RELAY_PIN`.

### Octoprint - PSU Control plugin
For the script, we only need **python3** and the **pyserial** dependency (if you have OctoPrint you must certain already have this dependency).

The script accepts only one param, "**on**" or "**off**".

To use it with the plugin, first we need to get the full path of the script. `$ pwd` can tell you that.

On the **PSU Control plugin** seetings set:
- Switching Method: **System Command**
- On System Command: `python3 <SCRIPT_FULL_PATH>/relay.py on`
- Off System Command: `python3 <SCRIPT_FULL_PATH>/relay.py off`

Enjoy!