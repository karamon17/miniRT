#include "../includes/miniRT.h"

char		*read_file(char *str, int fd)
{
    char	buf[BUFFER_SIZE + 1];
    char	*ptr;
    int		retairment;

    while ((retairment = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        ptr = str;
        buf[retairment] = '\0';
        if (!(str = ft_strjoin(str, buf)))
            return (NULL);
    }
    return (str);
}

void parse_rt_file(t_data *data) {
    int fd;
    char *file_content;

    if ((fd = open(data->filename, 0)) == -1)
        fatal();
    file_content = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    file_content = read_file(file_content, fd);
    printf("%s", file_content);
}
