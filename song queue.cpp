#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    char title[100];
    char artist[100];
    float duration;
    struct Song* next;
};

struct Song* head = NULL;
struct Song* tail = NULL;
int size = 0;

struct Song* createNode(char title[], char artist[], float duration) {
    struct Song* newSong = (struct Song*)malloc(sizeof(struct Song));

    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    newSong->duration = duration;
    newSong->next = NULL;

    return newSong;
}

int isEmpty() {
    return head == NULL;
}

void addSong(char title[], char artist[], float duration) {
    struct Song* newSong = createNode(title, artist, duration);

    if (isEmpty()) {
        head = newSong;
        tail = newSong;
    } else {
        tail->next = newSong;
        tail = newSong;
    }

    size++;
    printf("-> Added: %s by %s\n", title, artist);
}

void playNext() {
    if (isEmpty()) {
        printf("ERROR: The playlist is currently empty! Add some songs first.\n");
        return;
    }

    struct Song* temp = head;

    printf("... Now Playing ...\n");
    printf("-> Dequeued and Played: %s (%s)\n", temp->title, temp->artist);

    head = head->next;
    size--;

    if (head == NULL) {
        tail = NULL;
    }

    free(temp);
}

void viewPlaylist() {
    if (isEmpty()) {
        printf("Playlist is empty.\n");
        return;
    }

    struct Song* current = head;
    int i = 1;

    printf("\n--- Current Playlist (Next Up is Song 1) ---\n");

    while (current != NULL) {
        printf("[%d] %s (%s) - %.1f min\n",
               i,
               current->title,
               current->artist,
               current->duration);

        current = current->next;
        i++;
    }

    printf("-------------\n");
}

void getTotalDuration() {
    struct Song* current = head;
    float total = 0;

    if (isEmpty()) {
        printf("Total Duration: 0 minutes\n");
        return;
    }

    while (current != NULL) {
        total += current->duration;
        current = current->next;
    }

    printf("Total Duration of Playlist: %.1f minutes\n", total);
}

int main() {
    int choice, num;

    char title[20][100] = {
        "Stairway to Heaven",
        "Bohemian Rhapsody",
        "Imagine",
        "Hey Jude",
        "Hotel California",
        "Shape of You",
        "Blinding Lights",
        "Someone Like You",
        "Smells Like Teen Spirit",
        "Perfect",
        "Believer",
        "Thunder",
        "Counting Stars",
        "Faded",
        "Let Her Go",
        "Demons",
        "Radioactive",
        "Senorita",
        "Peaches",
        "Save Your Tears"
    };

    char artist[20][100] = {
        "Led Zeppelin",
        "Queen",
        "John Lennon",
        "The Beatles",
        "The Eagles",
        "Ed Sheeran",
        "The Weeknd",
        "Adele",
        "Nirvana",
        "Ed Sheeran",
        "Imagine Dragons",
        "Imagine Dragons",
        "OneRepublic",
        "Alan Walker",
        "Passenger",
        "Imagine Dragons",
        "Imagine Dragons",
        "Shawn Mendes & Camila Cabello",
        "Justin Bieber",
        "The Weeknd"
    };

    float duration[20] = {
        8.0, 5.9, 3.0, 7.2, 6.5,
        4.0, 3.3, 4.7, 5.0, 4.4,
        3.4, 3.1, 4.2, 3.5, 4.1,
        3.0, 3.1, 3.2, 3.3, 3.6
    };

    printf(" MUSIC PLAYLIST (LINKED LIST QUEUE) \n");

    do {
        printf("\n Initial Song Library \n");
        for (int i = 0; i < 20; i++) {
            printf("[%d] %s (%s) - %.1f min\n",
                   i + 1, title[i], artist[i], duration[i]);
        }

        printf("-----------------------------\n");

        printf("\n Playlist Menu \n");
        printf("1. Add Song to Playlist (Enqueue)\n");
        printf("2. View Current Playlist\n");
        printf("3. Play Next Song (Dequeue)\n");
        printf("4. Show Total Duration\n");
        printf("5. Exit\n");
        printf("-----------------------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter song number to add (1-20): ");
            scanf("%d", &num);

            if (num >= 1 && num <= 20) {
                addSong(title[num - 1], artist[num - 1], duration[num - 1]);
            } else {
                printf("Invalid choice.\n");
            }
        }
        else if (choice == 2) {
            viewPlaylist();
        }\
        else if (choice == 3) {
            playNext();
        }
        else if (choice == 4) {
            getTotalDuration();
        }

    } while (choice != 5);

    printf("Exiting Playlist Program. Goodbye!\n");

    return 0;
}
