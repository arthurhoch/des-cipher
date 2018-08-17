#include <stdio.h>
#include "block.h"

void nt_bits(block b);

// https://stackoverflow.com/questions/17052443/c-function-inside-struct

// typedef struct client_ops_t client_ops_t;
// typedef struct client_t client_t, *pno;

// struct client_t {
//     /* ... */
//     client_ops_t *ops;
// };

// struct client_ops_t {
//     pno (*AddClient)(client_t *);
//     pno (*RemoveClient)(client_t *);
// };

// pno AddClient (client_t *client) { return client->ops->AddClient(client); }
// pno RemoveClient (client_t *client) { return client->ops->RemoveClient(client); }