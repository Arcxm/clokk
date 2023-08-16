# clokk

Clokk is a cli tool that tells the time in a pretty way.

## Quick Start

Clone the repo and use make to build.

```console
$ make
$ clokk
```

### Timezones

Please note that you might have to change the `HOUR_CORRECTION` to get the correct time for your time zone. This might be fixed in the future.

## Digits

Clokk currently uses these digits composed of `#`:

```bash
#######       # ####### ####### #     # ####### ####### ####### ####### #######
#     #       #       #       # #     # #       #             # #     # #     #
#     #       #       #       # #     # #       #             # #     # #     #
#     #       # ####### ####### ####### ####### #######       # ####### #######
#     #       # #             #       #       # #     #       # #     #       #
#     #       # #             #       #       # #     #       # #     #       #
#######       # ####### #######       # ####### #######       # #######       #
```

