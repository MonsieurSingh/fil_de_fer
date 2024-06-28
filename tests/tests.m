//
//  tests.m
//  tests
//
//  Created by Teghjyot Singh on 27/6/2024.
//

#import <XCTest/XCTest.h>
#include "../fil_de_fer.h"

@interface tests : XCTestCase

@end

@implementation tests

- (void)setUp {
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

- (void)testSquareMaps {
	t_data	data;
	const char**	fake_argv;

	fake_argv = malloc(2);
	fake_argv[0] = "./fdf";
	fake_argv[1] = "/Users/teghjyot/Developer/fil_de_fer/test_maps/10-2.fdf";
	int res = verify(2, fake_argv, &data);
	XCTAssertFalse(res);
	XCTAssertEqual(data.map_width, 10);
	XCTAssertEqual(data.map_height, 10);
	fake_argv[1] = "/Users/teghjyot/Developer/fil_de_fer/test_maps/10-70.fdf";
	res = verify(2, fake_argv, &data);
	XCTAssertFalse(res);
	XCTAssertEqual(data.map_width, 10);
	XCTAssertEqual(data.map_height, 10);
	fake_argv[1] = "/Users/teghjyot/Developer/fil_de_fer/test_maps/20-60.fdf";
	res = verify(2, fake_argv, &data);
	XCTAssertFalse(res);
	XCTAssertEqual(data.map_width, 20);
	XCTAssertEqual(data.map_height, 20);
	fake_argv[1] = "/Users/teghjyot/Developer/fil_de_fer/test_maps/50-4.fdf";
	res = verify(2, fake_argv, &data);
	XCTAssertFalse(res);
	XCTAssertEqual(data.map_width, 50);
	XCTAssertEqual(data.map_height, 50);
	fake_argv[1] = "/Users/teghjyot/Developer/fil_de_fer/test_maps/100-6.fdf";
	res = verify(2, fake_argv, &data);
	XCTAssertFalse(res);
	XCTAssertEqual(data.map_width, 100);
	XCTAssertEqual(data.map_height, 100);
	fake_argv[1] = "/Users/teghjyot/Developer/fil_de_fer/test_maps/elem.fdf";
	res = verify(2, fake_argv, &data);
	XCTAssertFalse(res);
	XCTAssertEqual(data.map_width, 10);
	XCTAssertEqual(data.map_height, 10);
	fake_argv[1] = "/Users/teghjyot/Developer/fil_de_fer/test_maps/elem2.fdf";
	res = verify(2, fake_argv, &data);
	XCTAssertFalse(res);
	XCTAssertEqual(data.map_width, 20);
	XCTAssertEqual(data.map_height, 20);
	free(fake_argv);
}

- (void)testIrregularMaps {
	t_data	data;
	const char**	fake_argv;

	fake_argv = malloc(2);
	fake_argv[0] = "./fdf";
	fake_argv[1] = "/Users/teghjyot/Developer/fil_de_fer/test_maps/42.fdf";
	int res = verify(2, fake_argv, &data);
	XCTAssertFalse(res);
	XCTAssertEqual(data.map_width, 19);
	XCTAssertEqual(data.map_height, 11);
	fake_argv[1] = "/Users/teghjyot/Developer/fil_de_fer/test_maps/42.fdf";
	res = verify(2, fake_argv, &data);
	XCTAssertFalse(res);
	XCTAssertEqual(data.map_width, 19);
	XCTAssertEqual(data.map_height, 11);
	fake_argv[1] = "/Users/teghjyot/Developer/fil_de_fer/test_maps/basictest.fdf";
	res = verify(2, fake_argv, &data);
	XCTAssertFalse(res);
	XCTAssertEqual(data.map_width, 11);
	XCTAssertEqual(data.map_height, 9);
	fake_argv[1] = "/Users/teghjyot/Developer/fil_de_fer/test_maps/mars.fdf";
	res = verify(2, fake_argv, &data);
	XCTAssertFalse(res);
	XCTAssertEqual(data.map_width, 200);
	XCTAssertEqual(data.map_height, 116);
	fake_argv[1] = "/Users/teghjyot/Developer/fil_de_fer/test_maps/pentenegpos.fdf";
	res = verify(2, fake_argv, &data);
	XCTAssertFalse(res);
	XCTAssertEqual(data.map_width, 21);
	XCTAssertEqual(data.map_height, 9);
	fake_argv[1] = "/Users/teghjyot/Developer/fil_de_fer/test_maps/plat.fdf";
	res = verify(2, fake_argv, &data);
	XCTAssertFalse(res);
	XCTAssertEqual(data.map_width, 10);
	XCTAssertEqual(data.map_height, 14);
	fake_argv[1] = "/Users/teghjyot/Developer/fil_de_fer/test_maps/pnp_flat.fdf";
	res = verify(2, fake_argv, &data);
	XCTAssertFalse(res);
	XCTAssertEqual(data.map_width, 21);
	XCTAssertEqual(data.map_height, 9);
	fake_argv[1] = "/Users/teghjyot/Developer/fil_de_fer/test_maps/pylone.fdf";
	res = verify(2, fake_argv, &data);
	XCTAssertFalse(res);
	XCTAssertEqual(data.map_width, 48);
	XCTAssertEqual(data.map_height, 47);
	fake_argv[1] = "/Users/teghjyot/Developer/fil_de_fer/test_maps/pyra.fdf";
	res = verify(2, fake_argv, &data);
	XCTAssertFalse(res);
	XCTAssertEqual(data.map_width, 27);
	XCTAssertEqual(data.map_height, 27);
	fake_argv[1] = "/Users/teghjyot/Developer/fil_de_fer/test_maps/pyramide.fdf";
	res = verify(2, fake_argv, &data);
	XCTAssertFalse(res);
	XCTAssertEqual(data.map_width, 27);
	XCTAssertEqual(data.map_height, 34);
	free(fake_argv);
}

- (void)testColouredMaps {
	t_data	data;
	const char**	fake_argv;

	fake_argv = malloc(2);
	fake_argv[0] = "./fdf";
	fake_argv[1] = "/Users/teghjyot/Developer/fil_de_fer/test_maps/elem-col.fdf";
	int res = verify(2, fake_argv, &data);
	XCTAssertFalse(res);
	XCTAssertEqual(data.map_width, 10);
	XCTAssertEqual(data.map_height, 10);
	fake_argv[1] = "/Users/teghjyot/Developer/fil_de_fer/test_maps/elem-fract.fdf";
	res = verify(2, fake_argv, &data);
	XCTAssertFalse(res);
	XCTAssertEqual(data.map_width, 500);
	XCTAssertEqual(data.map_height, 500);
	fake_argv[1] = "/Users/teghjyot/Developer/fil_de_fer/test_maps/basictest.fdf";
	res = verify(2, fake_argv, &data);
	XCTAssertFalse(res);
	XCTAssertEqual(data.map_width, 11);
	XCTAssertEqual(data.map_height, 9);
	fake_argv[1] = "/Users/teghjyot/Developer/fil_de_fer/test_maps/julia.fdf";
	res = verify(2, fake_argv, &data);
	XCTAssertFalse(res);
	XCTAssertEqual(data.map_width, 500);
	XCTAssertEqual(data.map_height, 500);
	fake_argv[1] = "/Users/teghjyot/Developer/fil_de_fer/test_maps/t1.fdf";
	res = verify(2, fake_argv, &data);
	XCTAssertFalse(res);
	XCTAssertEqual(data.map_width, 200);
	XCTAssertEqual(data.map_height, 200);
	fake_argv[1] = "/Users/teghjyot/Developer/fil_de_fer/test_maps/t2.fdf";
	res = verify(2, fake_argv, &data);
	XCTAssertFalse(res);
	XCTAssertEqual(data.map_width, 100);
	XCTAssertEqual(data.map_height, 100);
	free(fake_argv);
}

//- (void)testPerformanceExample {
//    // This is an example of a performance test case.
//    [self measureBlock:^{
//        // Put the code you want to measure the time of here.
//    }];
//}

@end
