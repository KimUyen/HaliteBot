#!/usr/bin/env bash

set -e

cmake .
make MyBot
./halite -d "240 160" "./BasicBot" "./MyBot"
