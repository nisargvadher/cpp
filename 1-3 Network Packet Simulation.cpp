#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct packet
{
    int64_t arrtime;
    int64_t processtime;
};

int main()
{
    int64_t buffersize, totalpackets;
    cin >> buffersize >> totalpackets;
    if (totalpackets > 0)
    {
        // vector 'output' to store the time for each packet started processing
        vector<int64_t> output(totalpackets, 0);
        //ptr which navigates through output
        vector<int64_t>::iterator ptr = output.begin();

        // Below variables are used temporary in code which are explained later
        int64_t to_add;
        bool flag = true;

        // queue 'q' acts as a buffer. Front node acts as processing node and
        // packet is added at back
        queue<packet> q;

        packet *temp = new packet();

        cin >> temp->arrtime >> temp->processtime;
        q.push(*temp);

        //First node is always processed and hence is added to queue(buffer)
        output[0] = temp->arrtime;

        for (int64_t i = 1; i < totalpackets; i++)
        {
            temp = new packet();
            cin >> temp->arrtime >> temp->processtime;

            // When new packet to add has arrival time less than current node being processed
            // it is added to queue with a condition checked that buffer is not full.
            if ((temp->arrtime < ((*ptr) + q.front().processtime)) && (q.size() < buffersize))
            {
                q.push(*temp);
            }

            // If new packet being received has arrival time equal or greater than current node being processed
            // then we pop node currently processed and add new node to buffer.
            else if (temp->arrtime >= (*ptr) + q.front().processtime)
            {
                // Here we check for all the elements in the buffer before the new element being added that
                // its starting time + its processing time is less than or not. If it is less then we have to add it to buffer.
                // The condition to verify buffersize uses less than or Equal because we surely are going to pop current element
                //being processed which will reduce the buffer size by 1 (if FULL).
                // Other condition 'q.size() != 1' is used to prevent pointer setting other value i.e. calculating starting execution time
                // using previous starting time + processing time from output array.
                while (((*ptr) + q.front().processtime <= temp->arrtime) && (q.size() <= buffersize) && (q.size() != 1))
                {
                    ++ptr;
                    // We have to move ahead in output array if we have dropped a packet earlier for which we set -1 
                    //in output array. This code can be found in later sections of code.
                    while (*ptr == -1)
                    {
                        ++ptr;
                    }
                    if ((*ptr) != -1)
                    {
                        // This sets time of starting of execution of packet using previous starting time
                        // + previous processing time
                        (*ptr) = *(ptr - 1) + q.front().processtime;
                    }

                    q.pop();
                }
                if ((q.size() == 1) && ((*ptr) + q.front().processtime <= temp->arrtime))
                {
                    ++ptr;
                    while (*ptr == -1)
                    {
                        ++ptr;
                    }

                    
                    (*ptr) = temp->arrtime;
                    q.pop();
                }
                // After we have calculated time for starting exection of currently arrived packet
                // we add it to the queue (buffer)
                q.push(*temp);
            }
            // We drop the packet and sets its index in output array as (-1). This is why we check (-1)
            // while navigating pointer.
            else if (q.size() == buffersize)
            {
                output[i] = -1;
            }
        }

        // After all the input packets are processed, we check we have more than 1 element in queue to process or not.
        //  Because for the last one element we have already calculated its starting time and we donot need to process an further
        while (q.size() > 1)
        {
            // We just save time of currently being processed element from output array just in case 
            // we have to skip (-1) elements found in output array. We do this to prevent value being calculated
            // for a packet which used previous element which in this case would be -1 which will calculate wrong answer.
            // That is why we used 'to_add' variable and flag variable to decide whether to use it or not.
            to_add = (*ptr);
            ++ptr;
            if (*ptr == -1)
            {
                flag = false;
                while (*ptr == -1)
                {
                    ++ptr;
                }
            }
            if (flag == false)
            {
                (*ptr) = to_add + q.front().processtime;
            }
            else
            {
                (*ptr) = (*(ptr - 1)) + q.front().processtime;
            }
            q.pop();
        }
        
        // This just outputs the output array.
        for (int64_t i = 0; i < totalpackets - 1; i++)
        {
            cout << output[i] << "\n";
        }
        cout << output[totalpackets - 1];
    }
}

// Inputs.
// BufferSize //No of packets.
/* 
3 6
0 2
1 2
2 2
3 2
4 2
5 2
*/

/*
1 3
0 2
1 4
5 3
*/

/*
2 5
0 417
0 842
0 919
0 732
418 414
*/


