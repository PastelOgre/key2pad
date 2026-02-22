key2pad exists because there are games that don't offer
keyboard key rebinding, but offer controller support,
and there are those that rather play those games on the
keyboard.

key2pad requires the ViGEmBus driver to be able to add a
virtual x-box controller to be used in games. Install this driver
from: https://github.com/nefarius/ViGEmBus/releases

After installing the driver, edit button_config.ini to map
keyboard buttons to the virtual gamepad, then run
key2pad.exe to actually add the gamepad. The virtual gamepad
will be seen by Windows as long as key2pad is running.
