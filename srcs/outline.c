


/////////////////////////////	// stage 1 --> reading and processing input
/////////////////////////////	//		input --> first argument passed --> input file
/////////////////////////////	//		initate main object struct
//////////////////////////////	//		output --> linked list of vectors, max-min coordinates for x,y,z, linesize, dimensions (x_count * z_count = total_vectors)
//////////////////////////////	//		linesize can be used as an offset. --> an x and z mask the vector list. 

	// intermediate memory and performance check

////////////////////////////////	//	if (stage 1 == success) --> stage 2
	//		initiate window and image
	//		centre and copy original vectors list
	//		scale and copy original centered vector list
	//		set x and z grid masks for the scaled vector list

	// intermediate memory and performance check

	//	if (stage 2 == success) --> stage 3
	//		render scaled vector list into img using the x and z grid masks
	//		put img to window
	//		render interface
	//		activate event hooks (rotate, zoom, changeview, terminate)

	//	intermediate memory and performance check

	//	stage 4
	//	if (event == rotate || zoom || change view)
	//		set vectors in the scaled list to zero, while the grid masks remain the same
	//		apply change to centered vector list
	//		set and scale vector list into the list that is connected to grid masks
	//		--> goto stage 3
	//	else if (event == terminate)
	//		clear and free object struct
	//		destroy image and window
	//		exit program

	//	final memory and performance check