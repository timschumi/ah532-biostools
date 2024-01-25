# Fujitsu LIFEBOOK AH532 BIOS tools

## Disclaimer

Some of these tools work directly on the internals of the Laptop.
Do not attempt to use these tools on configurations that they aren't meant for.

I assume no liability for broken hardware or software due to correct or
incorrect usage of these tools.

## fixboot

This tool restores boot entries that were potentially corrupted by installing Linux.
The research leading up to the tool has been documented in a blog post [here](https://blog.timschumi.net/2024/01/20/ah532-bios-investigation.html).
If the laptop does not enter the BIOS setup menu, and the boot menu is either
inaccessible or does not show device-based entries, you are most likely experiencing
the issue that this tool tries to fix.

### Supported configurations

- Fujitsu LIFEBOOK AH532 (YLKV), firmware v1.04
- Fujitsu LIFEBOOK AH532 (YLKV), firmware v1.08
- Fujitsu LIFEBOOK AH532 (YLKV), firmware v1.09
- Fujitsu LIFEBOOK AH532 (YLKV), firmware v1.11
- Fujitsu LIFEBOOK A532, firmware v1.10 ([reported working by third-party](https://mastodon.social/@GromBeestje/111795580489425479))

### Potentially working configurations

The following devices have not been tested by me or by a third party.

There exist indicators that running the tool on these at least won't
break anything too hard, namely that the tool won't write any GUIDs
that are plain wrong.

In case you have success with any of these devices (or in case you
don't), please make sure to let me know. **The disclaimer still applies.**

- Fujitsu LIFEBOOK AH532/G21, firmware v1.08
- Fujitsu LIFEBOOK AH532/G21, firmware v1.09
- Fujitsu LIFEBOOK AH532/G21, firmware v1.10
- Fujitsu LIFEBOOK AH532/G21, firmware v2.09
- Fujitsu LIFEBOOK AH532/A532, firmware v2.09
- Fujitsu LIFEBOOK LH532 (UMA), firmware v1.10
- Fujitsu LIFEBOOK LH532/G22, firmware v1.07
- Fujitsu LIFEBOOK LH532/G22, firmware v1.08
- Fujitsu LIFEBOOK LH532/G22, firmware v1.10
- Fujitsu LIFEBOOK LH532/G22, firmware v2.06
