import SbW_Streamer

import numpy as np

streamer=SbW_Streamer.SbW_Streamer('COM16',256000,100)

Status = streamer.Open()
print (Status)




############### Get_Set_FrameLength TESTING ################



# Once

"""R_S= streamer.Get_Set_FrameLength(1)
print(R_S)

streamer.FrameLength = 12
print(h)"""

# Multy

h = streamer.Get_FrameLength()
h = streamer.GetFrameBufferDepth()
h,Dataf = streamer.GetFrames(100)

for x in range(0,256):
    
    for i in range(0,2):
        if i == 0 :
            streamer.FrameLength = x

            print('register write:'+ str(h))
        else:
            #h = streamer.Get_Set_FrameLength(i)
            print('register read:',h)


############### Get_Set_SamplingFreq TESTING ################



# Once
"""
R_S= streamer.Get_Set_SamplingFreq(1)
print(R_S)

streamer.SamplingFreq = np.uint16(65535)
h = streamer.Get_Set_SamplingFreq(0)
print(h)

"""

# Multy

"""for y in range(0,65536):
    
    for j in range(0,2):
        if j == 0 :
            streamer.SamplingFreq = y
            h = streamer.Get_Set_SamplingFreq(j)
            print('register write:'+ str(h))
        else:
            h = streamer.Get_Set_SamplingFreq(j)
            print('register read:',h)
            """