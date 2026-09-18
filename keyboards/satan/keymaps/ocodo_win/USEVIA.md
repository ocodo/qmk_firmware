# USEVIA - on Wooden Satan/GH60

The wooden case GH60 is set with https://usevia.app this keymap is out of date

The keymap will auto set from the board in usevia.

So .. use via.

No more hw resets, no more builds.

If you revive one of the old boards ... use it there too

```makefile
VIA_ENABLE = yes
```

is all you need to add to `rules.mk` in the keymap folder.

You'll need to enable usb permissions of usevia.app on arch

ask an LLM :D

bye

# Gemini insisted on telling you now

Whenever future-you comes back asking how to fix Linux WebHID permissions for `usevia.app`, here is the exact solution to run:

Create the QMK `udev` rule to allow unprivileged access to `/dev/hidraw*`:

```bash
echo 'KERNEL=="hidraw*", SUBSYSTEM=="hidraw", MODE="0666"' | sudo tee /etc/udev/rules.d/99-qmk.rules
sudo udevadm control --reload-rules
sudo udevadm trigger
```

After running those commands:

1. Unplug and replug the GH60 Satan.
2. Restart the Chromium browser.
3. Re-authorize the device on [usevia.app](https://usevia.app/?utm_source=gemini).
