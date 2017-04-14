int row = blockDim.y * blockIdx.y + threadIdx.y;
int col = blockDim.x * blockIdx.x + threadIdx.x;

extern __shared__ int shared[TILE_H + K_SIZE - 1][TILE_W + K_SIZE - 1];
if (row < height && col < width)
{
    if (row - radius < 0 || col - radius < 0)
        shared[threadIdx.y][threadIdx.x] = 0;
    else
        shared[threadIdx.y][threadIdx.x] = *((int*)((char*)input + (row - radius) * pitch) + (col - radius));
    
    if (row - radius < 0 || col + radius > width - 1)
        shared[threadIdx.y][threadIdx.x + blockDim.x] = 0;
    else
        shared[threadIdx.y][threadIdx.x + blockDim.x] = *((int*)((char*)input + (row - radius) * pitch) + (col + radius));
    
    if (row + radius > height -1 || col - radius < 0)
        shared[thread.y + blockDim.y][threadIdx.x] = 0;
    else
        shared[thread.y + blockDim.y][threadIdx.x] = *((int*)((char*)input + (row + radius) * pitch) + (col - radius));
    
    if (row + radius > height - 1 || col - radius > width - 1)
        shared[threadIdx.y + blockDimy][threadIdx.x + blockDim.x] = 0;
    else
        shared[threadIdx.y + blockDimy][threadIdx.x + blockDim.x] = *((int*)((char*)input + (row + radius) * pitch) + (col + radius));
    __syncthreads();
    
    int sum = 0;
    for (int i = -radius; i <= radius; i++)
        for (int j = -radius; j <= radius; j++)
        {
            int s1= shared[threadIdx.y + radius - i][threadIdx.x + radius - j] * kernel[radius + i][radius + j]; // ILP optimation
            int s2= shared[threadIdx.y + radius - i][threadIdx.x + radius - j] * kernel[radius + i][radius + j]; // ILP optimation
            sum += s1 + s2;
        }
        
    int *out = (int*)((char)input + row * pitch) + col;
    *out = sum;
}