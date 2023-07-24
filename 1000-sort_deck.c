#include "deck.h"

int compare_cards(const void *card1, const void *card2)
{
    const card_t *c1 = *(const card_t **)card1;
    const card_t *c2 = *(const card_t **)card2;

    int value_cmp = strcmp(c1->value, c2->value);
    if (value_cmp != 0)
        return value_cmp;

    return c1->kind - c2->kind;
}

void sort_deck(deck_node_t **deck)
{
    int num_cards = 0;
    deck_node_t *current = *deck;
    int i = 0;
    const card_t **cards_array = malloc(num_cards * sizeof(card_t *));
    
    while (current)
    {
        num_cards++;
        current = current->next;
    }

    if (!cards_array)
        return;

    current = *deck;
    while (current)
    {
        cards_array[i] = current->card;
        current = current->next;
        i++;
    }

    qsort(cards_array, num_cards, sizeof(card_t *), compare_cards);

    for (i = 0; i < num_cards - 1; i++)
    {
        (*deck)->card = cards_array[i];
        (*deck)->next = (*deck)->next->next;
        (*deck)->next->prev = *deck;
        deck = &(*deck)->next;
    }

    (*deck)->card = cards_array[i];
    (*deck)->next = NULL;

    free(cards_array);
}
