
#include <iostream>
#include <cstdlib>
#include <ctime>

#define LENGTH 50
using namespace std;

class Map {
public:
    int map[LENGTH][LENGTH] = { 0 };
    //    初始状态为全满
    struct generate_status {
        string direction = "";
        int counter = 0;
    };
    generate_status status;

    struct generator_way_point {
        int x;
        int y;
        generator_way_point* next;
        generator_way_point* last;

        generator_way_point(int x = 0, int y = 0) {
            this->last = NULL;
            this->x = x;
            this->y = y;
            this->next = NULL;
        }
    };

    //    路径点结构体
    generator_way_point* generator_up_point(generator_way_point* now) {
        generator_way_point* p = (generator_way_point*)malloc(sizeof(generator_way_point));
        now->next = p;
        p->last = now;
        p->x = now->x;
        p->y = now->y - 1;
        map[p->x][p->y] = 1;
        return p;
    }//1
    generator_way_point* generator_down_point(generator_way_point* now) {
        generator_way_point* p = (generator_way_point*)malloc(sizeof(generator_way_point));
        now->next = p;
        p->last = now;
        p->x = now->x;
        p->y = now->y + 1;
        map[p->x][p->y] = 1;
        return p;
    }//2
    generator_way_point* generator_left_point(generator_way_point* now) {
        generator_way_point* p = (generator_way_point*)malloc(sizeof(generator_way_point));
        now->next = p;
        p->last = now;
        p->x = now->x - 1;
        p->y = now->y;
        map[p->x][p->y] = 1;
        return p;
    }//3
    generator_way_point* generator_right_point(generator_way_point* now) {
        generator_way_point* p = (generator_way_point*)malloc(sizeof(generator_way_point));
        now->next = p;
        p->last = now;
        p->x = now->x + 1;
        p->y = now->y;
        map[p->x][p->y] = 1;
        return p;
    }//4
    generator_way_point*
    rand_direction(int up = 0, int down = 0, int left = 0, int right = 0, generator_way_point* now = nullptr) {
        if (now) {
            int dire_value = up + down + left + right;
            srand((int)time(NULL));
            int one_way_max_length = rand() % 5 + 3;
            switch (dire_value) {
                case 0:
                    return nullptr;
                    case 1:
                        if (up == 1) {
                            status.counter++;
                            status.direction = "up";
                            return generator_up_point(now);
                        }
                        else if (down == 1) {
                            status.counter++;
                            status.direction = "down";
                            return generator_down_point(now);
                        }
                        else if (left == 1) {
                            status.counter++;
                            status.direction = "left";
                            return generator_left_point(now);
                        }
                        else if (right == 1) {
                            status.counter++;
                            status.direction = "right";
                            return generator_right_point(now);
                        }
                        break;
                        case 2:
                            if (up == 1 && down == 1) {
                                if (status.direction == "up" && status.counter < one_way_max_length) {
                                    status.counter++;
                                    return generator_up_point(now);
                                }
                                else {
                                    status.counter = 1;
                                    status.direction = "down";
                                    return generator_down_point(now);
                                }
                            }
                            else if (up == 1 && left == 1) {
                                if (status.direction == "up" && status.counter < one_way_max_length) {
                                    status.counter++;
                                    return generator_up_point(now);
                                }
                                else {
                                    status.counter = 1;
                                    status.direction = "left";
                                    return generator_left_point(now);
                                }
                            }
                            else if (down == 1 && left == 1) {
                                if (status.direction == "down" && status.counter < one_way_max_length) {
                                    status.counter++;
                                    return generator_down_point(now);
                                }
                                else {
                                    status.counter = 1;
                                    status.direction = "left";
                                    return generator_left_point(now);
                                }
                            }
                            else if (up == 1 && right == 1) {
                                if (status.direction == "up" && status.counter < one_way_max_length) {
                                    status.counter++;
                                    return generator_up_point(now);
                                }
                                else {
                                    status.counter = 1;
                                    status.direction = "right";
                                    return generator_right_point(now);
                                }
                            }
                            else if (down == 1 && right == 1) {
                                if (status.direction == "down" && status.counter < one_way_max_length) {
                                    status.counter++;
                                    return generator_down_point(now);
                                }
                                else {
                                    status.counter = 1;
                                    status.direction = "right";
                                    return generator_right_point(now);
                                }
                            }
                            else if (left == 1 && right == 1) {
                                if (status.direction == "left" && status.counter < one_way_max_length) {
                                    status.counter++;
                                    return generator_left_point(now);
                                }
                                else {
                                    status.counter = 1;
                                    status.direction = "right";
                                    return generator_right_point(now);
                                }
                            }
                            break;
                            case 3:
                                if (up == 0) {
                                    if (status.direction == "left" && status.counter < one_way_max_length) {
                                        status.counter++;
                                        return generator_left_point(now);
                                    }
                                    else if (status.direction == "down" && status.counter < one_way_max_length) {
                                        status.counter++;
                                        return generator_down_point(now);
                                    }
                                    else if (status.direction == "right" && status.counter < one_way_max_length) {
                                        status.counter++;
                                        return generator_right_point(now);
                                    }
                                    else {
                                        switch (((int)rand() % 6)) {
                                            case 0:
                                                status.counter = 1;
                                                status.direction = "down";
                                                return generator_down_point(now);
                                                break;
                                                case 1:
                                                    case 3:
                                                        status.counter = 1;
                                                        status.direction = "left";
                                                        return generator_left_point(now);
                                                        break;
                                                        case 2:
                                                            case 4:
                                                                case 5:
                                                                    status.counter = 1;
                                                                    status.direction = "right";
                                                                    return generator_right_point(now);
                                                                    break;
                                        }
                                    }
                                }
                                else if (down == 0) {
                                    if (status.direction == "left" && status.counter < one_way_max_length) {
                                        status.counter++;
                                        return generator_left_point(now);
                                    }
                                    else if (status.direction == "up" && status.counter < one_way_max_length) {
                                        status.counter++;
                                        return generator_up_point(now);
                                    }
                                    else if (status.direction == "right" && status.counter < one_way_max_length) {
                                        status.counter++;
                                        return generator_right_point(now);
                                    }
                                    else {
                                        switch (((int)rand() % 6)) {
                                            case 0:
                                                case 3:
                                                    case 4:
                                                        status.counter = 1;
                                                        status.direction = "up";
                                                        return generator_up_point(now);
                                                        break;
                                                        case 1:
                                                            status.counter = 1;
                                                            status.direction = "left";
                                                            return generator_left_point(now);
                                                            break;
                                                            case 2:
                                                                case 5:
                                                                    status.counter = 1;
                                                                    status.direction = "right";
                                                                    return generator_right_point(now);
                                                                    break;
                                        }
                                    }
                                }
                                else if (left == 0) {
                                    if (status.direction == "down" && status.counter < one_way_max_length) {
                                        status.counter++;
                                        return generator_down_point(now);
                                    }
                                    else if (status.direction == "up" && status.counter < one_way_max_length) {
                                        status.counter++;
                                        return generator_up_point(now);
                                    }
                                    else if (status.direction == "right" && status.counter < one_way_max_length) {
                                        status.counter++;
                                        return generator_right_point(now);
                                    }
                                    else {
                                        switch (((int)rand() % 6)) {
                                            case 0:
                                                status.counter = 1;
                                                status.direction = "down";
                                                return generator_down_point(now);
                                                break;
                                                case 1:
                                                    case 3:
                                                        status.counter = 1;
                                                        status.direction = "up";
                                                        return generator_up_point(now);
                                                        break;
                                                        case 2:
                                                            case 4:
                                                                case 5:
                                                                    status.counter = 1;
                                                                    status.direction = "right";
                                                                    return generator_right_point(now);
                                                                    break;
                                        }
                                    }
                                }
                                else if (right == 0) {
                                    if (status.direction == "left" && status.counter < one_way_max_length) {
                                        status.counter++;
                                        return generator_left_point(now);
                                    }
                                    else if (status.direction == "up" && status.counter < one_way_max_length) {
                                        status.counter++;
                                        return generator_up_point(now);
                                    }
                                    else if (status.direction == "down" && status.counter < one_way_max_length) {
                                        status.counter++;
                                        return generator_down_point(now);
                                    }
                                    else {
                                        switch (((int)rand() % 3)) {
                                            case 0:
                                                status.counter = 1;
                                                status.direction = "down";
                                                return generator_down_point(now);
                                                break;
                                                case 1:
                                                    case 3:
                                                        status.counter = 1;
                                                        status.direction = "left";
                                                        return generator_left_point(now);
                                                        break;
                                                        case 2:
                                                            case 4:
                                                                case 5:
                                                                    status.counter = 1;
                                                                    status.direction = "up";
                                                                    return generator_up_point(now);
                                                                    break;
                                        }
                                    }
                                }
                                break;
            }
        }
    }
    int judge_up(generator_way_point* now) {
        int x = now->x;
        int y = now->y;
        if (y == 0/*上边界*/ || map[x][y - 1] == 1/*回头路*/) { return 0; }
        else if ((x >= 1 && x <= LENGTH - 2)/*map[x-1][y]==0&&map[x+1][y]==*/
        && map[x - 1][y - 1] == 0 && map[x][y - 1] == 0 && map[x + 1][y - 1] == 0) {
            return 1;
        }
        else return 0;
    }
    int judge_down(generator_way_point* now) {
        int x = now->x;
        int y = now->y;
        if (y == LENGTH - 1/*边界*/ || map[x][y + 1] == 1/*回头路*/) { return 0; }
        else if ((x >= 1 && x <= LENGTH - 2)
        /*&&map[x-1][y]==0&&map[x+1][y]==0*/
        && map[x - 1][y + 1] == 0 && map[x][y + 1] == 0 && map[x + 1][y + 1] == 0) {
            return 1;
        }
        else return 0;
    }
    int judge_left(generator_way_point* now) {
        int x = now->x;
        int y = now->y;
        if (x == 0/*left边界*/ || map[x - 1][y] == 1/*回头路*/) { return 0; }
        else if ((y >= 1 && y <= LENGTH - 2)
        /*&&map[x][y-1]==0&&map[x][y+1]==0*/
        && map[x - 1][y + 1] == 0 && map[x - 1][y] == 0 && map[x - 1][y - 1] == 0) {
            return 1;
        }
        else return 0;
    }
    int judge_right(generator_way_point* now) {
        int x = now->x;
        int y = now->y;
        if (x == LENGTH - 1/*right边界*/ || map[x + 1][y] == 1/*回头路*/) { return 0; }
        else if ((y >= 1 && y <= LENGTH - 2)
        /*&&map[x][y-1]==0&&map[x][y+1]==0*/
        && map[x + 1][y + 1] == 0 && map[x + 1][y] == 0 && map[x + 1][y - 1] == 0) {
            return 1;
        }
        else return 0;
    }
    generator_way_point* generator_through_way(generator_way_point* now) {
        int up = 1;
        int down = 1;
        int left = 1;
        int right = 1;
        up = judge_up(now);
        down = judge_down(now);
        right = judge_right(now);
        left = judge_left(now);
        return rand_direction(up, down, left, right, now);
    }
    generator_way_point generate_all_through_way(void) {
        srand(time(0));
        generator_way_point start = generator_way_point();
        start.x = (int)rand() % (LENGTH - 2);
        start.y = 0;
        map[start.x][0] = 1;
        //        showmap();
        start.next = generator_through_way(&start);
        generator_way_point* p = start.next;
        while (1) {
            p->next = generator_through_way(p);
            if (p->next) {
                p = p->next;
                showmap();
            }
            else {
                break;
            }
        }
        return start;
    }
    void clean_all_trough_way(generator_way_point *start){
        generator_way_point * temp=start;
        while (temp->next)
        {
            temp = temp->next;
        }
        while (temp->last){
            start=temp->last;
            map[temp->x][temp->y]=0;
            free(temp);
            temp=start;
        }
    }
    generator_way_point generate(void) {
        generator_way_point temp = generate_all_through_way();
        generator_way_point* tail = NULL, * start = &temp;
        while (temp.next)
        {
            temp = *temp.next;
        }
        while (temp.y < LENGTH - 5) {
            clean_all_trough_way(start);
            temp = generate_all_through_way();
        }
        showmap();
        return temp;
    }
    void showmap() {
        system("cls");
        for (int i = 0; i < LENGTH; i++) {
            for (int j = 0; j < LENGTH; j++) {
                printf("%d", map[j][i]);
            }
            printf("\n");
        }
        printf("\n");
        printf("\n");
        printf("\n");
        //system("pause");
        return;
    }
};


int main() {
    Map map;
    map.generate();
}
