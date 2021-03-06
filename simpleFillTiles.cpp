//tileParamList consists the coordiantion of points that we want to extract from the WSI

	const int x = tileParamList[indexInTileParams][0];
	const int y = tileParamList[indexInTileParams][1];


	if (dynamic_cast<OwnOpenSlide*>(osr) != nullptr)
	{
// here we use a buffer to save the ecxtracted image
		auto* buf = static_cast<uint32_t*>(malloc(origTileWidth * origTileHeight * 4));
		const auto k = dynamic_cast<OwnOpenSlide*>(osr);
// In get bestlevel you specify the magnification that you want from the WSI to processed.
		k->fillImage(x, y, buf, getBestLevel(osr, optimumDs), origTileWidth, origTileHeight);
		src = cv::Mat(origTileHeight, origTileWidth, CV_8UC4, buf);

		src = cv::Mat(292, 292, CV_8UC4, buf);
		imwrite("src.png", src);

	}