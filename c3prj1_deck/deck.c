#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "deck.h"

void print_hand(deck_t *hand) {
    for (size_t i = 0; i < hand->n_cards; i++) {
        print_card(*(hand->cards[i]));
        printf(" ");
    }
}

int deck_contains(deck_t *d, card_t c) {
    for (size_t i = 0; i < d->n_cards; i++) {
        if (d->cards[i]->value == c.value && d->cards[i]->suit == c.suit) {
            return 1;  // Card found in the deck
        }
    }
    return 0;  // Card not found in the deck
}

void shuffle(deck_t *d) {
    size_t n = d->n_cards;
    for (size_t i = 0; i < n; i++) {
        size_t j = i + random() / (RAND_MAX / (n - i) + 1);
        // Swap pointers at positions i and j
        card_t *temp = d->cards[i];
        d->cards[i] = d->cards[j];
        d->cards[j] = temp;
    }
}

void assert_full_deck(deck_t *d) {
    for (size_t i = 0; i < 52; i++) {
        card_t c = card_from_num(i);
        assert(deck_contains(d, c) == 1);  // Each card should be in the deck exactly once
    }
}
