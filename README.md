# Password Strength
<!--
The first paragraph of this file should be kept short as it will be used as the
project summary on BackdropCMS.org. Aim for about 240 characters (three lines at
80 characters each).

All lines in this file should be no more than 80 characters long for legibility,
unless including a URL or example that requires the line to not wrap.
|<- - - - - - - This line is exactly 80 characters for reference - - - - - - ->|

Detail in READMEs should be limited to the minimum required for installation and
getting started. More detailed documentation should be moved to a GitHub wiki
page; for example: https://github.com/backdrop-contrib/setup/wiki/Documentation.
-->
Password Strength module provides realistic password strength measurement and
server-side enforcement for Backdrop CMS sites using pattern-matching and
entropy calculation. Almost any type of password can be allowed so long as the
password proves to be of high enough entropy.

## More Details
### How it's different
Other password enforcement tools are simplistic: they work by checking passwords
on explicit rules like character count and amount of varying character types
(symbols, numbers, uppercase letters, etc). A string like “Password1” will prove
acceptable to such systems but are obviously weak and easily brute-forced.

### How it works
Instead of checking on strict rules, Password Strength classifies the expected
brute-force time for the summed entropy of common underlying patterns in the
password. Patterns that can be detected in passwords include:

- Words that are found in a dictionary of common words, common first and last
names, or common passwords.
- Words that are found in the dictionary, but with common "1337" or "leet"
substitutions, such as 4 or @ for a, and 5 for s.
- Common sequences of letters (abcde), numbers (12345), or characters spatially
near each other on common keyboards (qwerty).
- Three or more of the same characters, such as "aaa" or "8888".
- Dates or years, such as "1921" or "19-11-1978."

## Requirements
Password Strength relies on the bundled PHP library
[Zxcvbn-PHP](https://github.com/bjeavons/zxcvbn-php) for password complexity
measurement. There is no need to download this library.

## Installation
<!--
List the steps needed to install and configure the module. Add/remove steps as
necessary.
-->
- Install this module using the official Backdrop CMS instructions at
  https://docs.backdropcms.org/documentation/extend-with-modules.
- Configure the Password Strength you wish to use at:
    Admin > Configuration > User accounts > Password Stength
    (`admin/config/people/password-strength`)

## Issues
<!--
Link to the repo's issue queue.
-->
Bugs and Feature Requests should be reported in the Issue Queue:
https://github.com/backdrop-contrib/password_strength/issues.

## Current Maintainers
<!--
List the current maintainer(s) of the module, and note if this module needs
new/additional maintainers.
-->
- [Martin Price](https://github.com/yorkshire-pudding) - [System Horizons Ltd](https://www.systemhorizons.co.uk)
- Collaboration and co-maintainers welcome!

## Credits
<!--
Give credit where credit's due.
If this is a Drupal port, state who ported it, and who wrote the original Drupal
module. If this module is based on another project, or uses third-party
libraries, list them here. You can also mention any organisations/companies who
sponsored the module's development.
-->
- Ported to Backdrop CMS by - [Martin Price](https://github.com/yorkshire-pudding) - [System Horizons Ltd](https://www.systemhorizons.co.uk).
- Port sponsored by [System Horizons Ltd](https://www.systemhorizons.co.uk).
- Created for Drupal by [Jeff Beeman](https://www.drupal.org/u/jrbeeman)
- This module relies on and includes [Zxcvbn-PHP](https://github.com/bjeavons/zxcvbn-php)
created and maintained by [Benjamin Jeavons](https://github.com/bjeavons)

## License
<!--
Mention what license this module is released under, and where people can find
it.
-->

This project is GPL v2 software.
See the LICENSE.txt file in this directory for complete text.

Zxcvbn-PHP is licensed with the MIT License. See the license file at
`libraries/ZxcvbnPhp/LICENSE.txt` for complete text.
