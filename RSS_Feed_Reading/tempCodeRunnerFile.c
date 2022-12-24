    if(pipe(fd) == -1){
        error("Can't create pipe");
    }