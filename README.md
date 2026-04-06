# How to play Tiến lên miền Nam
Tiến lên miền Nam is a Vietnamese card game that uses a standard 52-card deck and shares the same DNA as the President card game. The goal for each player is to discard all of their cards off their hand first.

# Setup
The 52 cards are all dealt between the players. Some people only prefer dealing 13 cards for each player when there are less than 4 players. We recommend playing this with 4 players.

# Turn determination
Players take turn discarding all of their 3s, the one with the 3 of Spades plays first.

# Rounds
A round starts with a person, specifically the one with the 3 of Spades starts the first round, and rounds after that has a person starts with the one winning the round before. A round consists of player taking turns playing combinations of cards and if you don't have a combination that can beat the combination given, you must choose to opt out of the round and won't play the round until a new round comes in. Optionally, if you have a combination that beats the given combination, you can also choose to opt out, which you won't have the ability to play the round.

# Card rankings
The "strength" of each card is defined in these 2 rules. We will assume that our 2 cards are `A` and `B` for the purpose:
1. If `A` has a stronger rank than `B`, then `A` is a stronger card than `B`
2. If `A` and `B` both have the same rank, then if `A` has a stronger suit than `B` then `A` is a stronger card than `B`

The order of strength of the parameters are as follows:
- Suits: `Spades` < `Clubs` < `Diamonds` < `Hearts`
- Ranks: `3` < `4` < `5` < `6` < `7` < `8` < `9` < `10` < `J` < `Q` < `K` < `A` < `2`

# Card combinations
There are 7 kinds of card combinations you can play, which includes:
1. Single
2. Pair
3. Triple
4. Straight
5. Four of a kind
6. Three consecutive pairs
7. Four consecutive pairs

# Singles
This only consists of a single card play. To beat this combination, either you have to play another single card that is stronger than the card given, or play a `four of a kind`, `three consecutive pairs`, or `four consecutive pairs`

# Pairs
This combination consists of 2 cards with the same rank. To beat this combination, either you play another pair that is stronger than the pair given, or play a `four of a kind` or `four consecutive pairs`. Pair `A` is stronger than pair `B` if the strongest card from `A` is stronger than the strongest card from `B`

# Triples
This combination consists of 3 cards with the same rank. To beat this combination, either you play another triple that is stronger than the triple given, or play `four consecutive pairs`. Triple `A` is stronger than triple `B` if the strongest card from `A` is stronger than the strongest card from `B`

# Straights
This combination consists of a list of cards with their ranks can be listed consecutively from their weakest rank to their strongest rank. For example: `5 6 7 8 9` is a straight that is 5 cards long. To beat this combination, either you play another straight with the same length that is stronger than the straight given, or play a `four of a kind`, `three consecutive pairs`, or `four consecutive pairs`. Straight `A` is stronger than straight `B` if the strongest card from `A` is stronger than the strongest card from `B`

# Three consecutive pairs
This combination consists of 3 pairs, in which each pair's rank can be listed consecutively from the weakest to the strongest. For example: `6 6 7 7 8 8` are three consecutive pairs. To beat this combination, either you play three consecutive pairs that are stronger than given, or play `four consecutive pairs`. A set of three consecutive pairs `A` is stronger than a set of three consecutive pairs `B` if the strongest card from `A` is stronger than the strongest card from `B`