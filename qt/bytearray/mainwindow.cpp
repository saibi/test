#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	QByteArray test;

	test.append(49);
	test.append(46);
	test.append(49);
	test.append(56);
	test.append(48);
	test.append(48);
	test.append('\n');
	test.append((char)0);
	test.append(char(0));
	test.append(char(0));
	test.append(char(0));
	test.append(char(0));


	qDebug("org [%s], size %d", test.constData(), test.size());

	QByteArray test3 = test.simplified();

	qDebug("simplified [%s] size %d", test3.constData(), test3.size());


	QByteArray test4 = test.trimmed();

	qDebug("trimmed [%s] size %d", test4.constData(), test4.size());

	float val = test3.toFloat();

	qDebug("value = %f", val);

	if ( test.contains('\n'))

	{
		QByteArray test2 = test.left( test.indexOf('\n'));



		qDebug("%d test2 [%s]", test.indexOf(char(0)), test2.constData());
	}

	test.clear();
	test.append('H');
	test.append('e');
	test.append('l');
	test.append('l');
	test.append('o');
	test.append('H');
	test.append('e');
	test.append('l');
	test.append('l');
	test.append('o');
	test.append('H');
	test.append('e');
	test.append('l');
	test.append('l');
	test.append('o');
	test.append('H');
	test.append('e');
	test.append('l');
	test.append('l');
	test.append('o');
	test.append('H');
	test.append('e');
	test.append('l');
	test.append('l');
	test.append('o');
	test.append('H');
	test.append('e');
	test.append('l');
	test.append('l');
	test.append('o');

	QByteArray hexForm = test.toHex();
	qDebug("org [%s], hex [%s]", test.constData(), hexForm.constData());

	QByteArray fromHex = QByteArray::fromHex("48656c6c6f");
	qDebug("restore [%s]", fromHex.constData());

	QByteArray cp = qCompress(test);
	qDebug("compress [%s], size %d", cp.constData(), cp.size());

	QByteArray up = qUncompress(cp);
	qDebug("uncompress [%s], size %d", up.constData(), up.size());


	//2016-09-03T15:25:54 [REM=HVMB=3008;28195;
//	QByteArray orgData = qUncompress(QByteArray::fromHex("00000bc0789cb5d60d4c95d719077094e8b4ef39cf39ef398f56a2e9b0b4ac55a2809f140cc64846c48ed50ea6921298936afd6cb1323f86d33a1d8ad1d23aadd561ec309546a6ce8f2ad8ea243aaac3696bfd984231b568e707ab55198aec7f0f17accbba2c4d767fb9971b2e970bef39e7fffc23c2a7654f7f357b6a787a6c7c4c747c6c74cca0e8b8e801d1b8c5c48f898f193810df1c121f1b1f17dd2ff02cf0d86a109ee26bbfc1818781d121dfed96a9339ccca09fb9fb7f93f91f047ec3589dd66e0ca4ead13a5927c108480c8ad3b14e7f1d05913a02c2a1970ed36d37a94374936a754735a86bf0a5aa579fab3a754e9d764ea8a3aa527d00e5ea7d55a64ad4262856eb55915aa90ad412b5482d50b3d5543559e5a82c18af7eac46a9e1ea19350462d40f546fd543f940aa8bba4bb7e0065da1f3f4297d4cc7e830eda7bdf4472aa58db481d6d0ebb49416523ee5d1cb348532298d522985922881e2289622c892a4aed49942a841d6cb3ab8204fc883f27d67872c91ab651114ca45728e9c0d3365961c0fe972941cee0c9331f209a7b7ec2129a88bec281b45a3b825be1297c5257151d48ab3e2241c1755a2426c135b9d52b151ac71de14cbc462b110f2c55cf1b298041345b6c814692255a438492241f477a24484f83e8489ee428aae4ea868f61a9c6b5ebd57e79cf33ef1aae1a877c4fb00cabd5dde7628f3def53641b1f7b6b7d62bf2567a8550e02df21678f39dd9de0c6f72508e97e5bd1034ae5dfa37bea6c38357db7e36eb2113827260f243a6b64b10ad12c588ff4962f0b1f53d89c167df2eb15de07d494e3204ae6eaa181334163271edb3b10253c474acc62c918755c977ebb3182bb542acc29a6d10efc056ace60171184e8af358e75aacf70dacfc2dacff5dd1517a92654f785c46c90172082460df8c9713658e9c827db5582e91cbe50af9b62cc59edb25f7c92a7956d6c8cfe575d92c43e911d2144e91348086d328fa09f6f1447a855ea3155444c5b48dcae94f74846ae826dda78eea7b4aa9c7542ccecc709582133455e5a95fa942b54e6d5515387f1fa9b3ea866a541d7066c3719e07e9789cf9f1fa259dabe7ea25fa2dbd45efd07bf5617d4a5fd257f56ddda285dfcb8ff0fbf843fc91fe737e863fc97fc59fe717fabff537fa9bfd3d7ea55fed9ff26bfd2bfe3dbfb3d1e651d3dbf43543cd08936ad2cd0433d3cc358bcd72b3da149b2d66b739608e9813e6b4a933d74da3b96f3a59657bd8c7ed53b6bf1d6a13ed689b6633ed443bddceb2f976a95d61dfb0c5b6c496d93d76bf3d64abec495b63bfb057ed3f6cb3edccc4cc61dc9b23b92f47f3501ec623f8879ccacf73064fe0177906e7721ee7f3125ec6aff36a5ecbebf91ddecca5bc9577f21edec7fbf9001fe22a3ec6d57c823fe5b35cc39ff125aee72bfc77bec65ff34ddc6f7113dfe516bec7cddca15b876e1d1f12f84e08b4f07dbc7e8feff06dbca781aff355fe922ff3175cc7b57c01cef0293e8ecffa0b7f844f3d804fdfc7bb791b6fc1dfb4897fc76b781517f0af7921cfe15ff034cee14c4ee731fc2c27e37f1bca03f07f46f2636c5872170ee5267bdd5eb417ec697bdc1eb6fbec4e5ca912bb1e57ed35fb4b5cc329b89a6936d526d9c136ca46d830ab6da8fda7b961ae98f3e698f9d0ec327f302566adf98dc93779669a79d18c33a3b17e834c3ff3a4e969a40935cdfe0dffa27f066b7dd0df8e955fe7bfe117f8f3b11b7ee4a760673ce347fbe1bef585dfa26f61ef9cd1d5ba5297eb32bd462fd70bf52c9dad9fd3297aa41eaa9fd4dd74277d4fdd565730192a311176611ebca596aa7cf52af23f1db93f420d567db09735f674235da3bfd15fe9287d4865b41ec95e805c7f89c6e13c8c429e3f8513124682eecbaf91e49fc98f6585dced12bc48ae447acf96d3e4cfe54f658a4c4262f7c3590c978f4a2143648b68c2496d1057458d4be86a9ce50a512e768aed48e7df239f37209b57b9740e08a4f33ca4c12ce4c294a0d6a40e6475a6c870c622b5d3f0d89628a94129df2af9ff2ae9dfccf61ec87566b8fb8c879eb76672db0c68d396e36db9fe20f7d3839e77d2bfa16d663c980213f09b7383e663ea2c720a3085564211acc664dae49560520594616a9563821d748e60a69d704e7b17dca4ab8706ef8ed704cd5e08a661574c462934266418a665a478da8912b122ae7dbe24b955198b15cb74693fc9657d20eddbb27ea94bfa75ce06b1197ba2d4257e853884c4afc23c3f897d13508b297f19c9ff5530f9ef8b2ec87e0f6d80d10c7aa321f4415788c1fe1b89f690ee7a44166640ae9c2f17608f1662afae95c572937c0f3bb75cfe195d24e013790eb3e09abc094d98075d310f2c75875ee83051683283d06712289192692c654036dace2cb49e79b40c27e54d34a135b40e9da814dd68371ad25ef4a443741cade93cd4d245ba8a2675975a303f3a290ffdaa87ea8993f784eaab06aa619824c3711e9fc5a91c0f2fa80938a133552ebada1c34b645e86e856870456ab55a8b36578c93fcae7a4fed8072b4bd835089ee17508dd37e4ed538756887f5688981aed80077d01d437428748647309fb44650e9eee89961689bbd5ceb8cd44f435450ffa0583dd889731220d175d85649ed92e15f303801bc"));
//	qDebug("size = %d, crc = %d", orgData.size(), qChecksum(orgData.constData(), orgData.size()));


	// 2015-09-03T15:25:30 [REM=HVFB=31808;22711;
	QByteArray orgData = qUncompress(QByteArray::fromHex("00007c40789ced9d07985445ba864fd9e64e838ca71a654d189695959c41104992b3089283e434a4010419728e431e18861c25e70c12154510164c0bab8b62420c98d0fbd55f75ead4e9ee415cd7bd7bef33e77d6086457abaabfeff3dd5d5fbd497eb81b66dda746ad3e381d62d7ab678a041a192f9f3952c902f7fe17cc5f315cc872b7fc93a25f3172a94af64c19245f2172e5cb27091a2454be62b5938df13f9f29514bf15c84f5ff2e72f991f5feeb47ee335d3e765d6bf4cf4234966c430dd609a8754cd54df9428262b26692682098af1be719ab1608c62b46f143192180186fb8629868221be14c560df4b8a41be81e0453080e8efeb0792415fa20fd1dbd7cbd79348023d7cdd7ddd7c5d155d7c9d7d9d888ebe0ebef68a76be177c6d8936a035d1cad79268e16bae68e66baa68e27b5ed11834523ce76b483cab68e0ab0fea29eafaea286a835a8a9abe1a9aeabe6a9aaabe2a8a6788caa092a222a8a028af781a94533c45945594219e244a6b4a694a821206c56328667c2da6fe544c7ff77f19f75597d4c85171474a8c9b184131967264cbd1680bcaab5910335289e648f08c42cc5e55cc6575c299e59a98f5da84a885ba4054477da2011095d310b5246884ea9275d60455d78c688e8a94b4448db6a25a1555db16352c68877aee40bf3a0259eb9d155d54177403ddd11912d125b25f7a697a13a29b6467891eeba7e9af115df8a262a06690c14b0683899418864431348a61510cbf0e2314236f9051318cfe37304a7fbd1ed1cf455ad0c1fb9a871a6674711de9e0ba7290312303b53307a89973e63259f933d930a8b4686f32a9e3d29ee452497772aa4438b58baa2fe955d7aced9459db28afb65238566da69cda441955dad4f56803d517f5b43b4d6b5657c6ac4ab6741de9f8b1bc76a2d7864f1a0e74bade745f3145514d91b8148e4ba1ff35dc9fee3c93f8cfafb0f15fff51cfd9fc89ee88b9235acc20d6c4eeddc9eb61d3c5a68f25d2c82e8e992b2a3f7b0deddc5fab2a1c4f7b5d5d53555c6d5d81d2d975d55dddf5b6ebee86cadf8da89e1d7f9b066f1e65f0368ab61e8b4b3a108ec93bc5f1b8204913eb71d7e27d0d8b3bf61ea0ed6dfada6b6ac7c9d106764d1b6bcf311ab1ea1b67301eabc2891a77d538d943f42ad3616a14a99992c6e610691af3fb78cc89c36c6296662698c1a6b369442a98aa98cc261113d904309e8d0363c118369a8d548c6043d910450a7b890d2206b217d900d69ff523fab23eac17eb0992580fd68d75619d4127d691b567edd80bac2d6bc35ab396ac396bc69ab226a0317b8e3dcbeab37aac2ea8cd6ab2eaac2aab029e61955879f634788a9561a558495682156745596156881560f9d813ecaf2c0ffb0bfb337b943dc21e660fb107d89fd8bdec1e96837176374b64d95998f9d99dec0e763bbb95ddc42cf68bf58bf5b3f5a375d5fa86f8caba6c7d4a5cb23eb23e24fe61bd6fbd07deb5ce597f23ce58a7ac13c41bd671eb55c531eb8875081cb45eb1f6837dd65e6b8fb50becb476585bad8d8a0dd63a6b0df1b2b5ca5a412cb796594bac4560a1b5c0cab0d2ad79d65c628e35cb9a4e4cb3a65a53c0646b9235c11a4f8cb3c658238911d6706b2831c41a6cbd04065903ad01a0bfd5cf4a067dad3e562fa2a79564f5b0ba5bdd4057ab8bd5d9ea4474b4da5bed142f586d34ad33a54d0c6d3dbca0108fd8de4387283a824eff213a832ea02b8d40378c84a00746a527e88571ea0b92316efd690407622cc5880eb652ac6118e791d6288cfb78ccc244cc462a66661ae66736e62a0d33371f2cc46c2e05cbac9598e3559869c17a6b93b5196c433dec445dec468d1c40b51c44d51c4105bd065e47559d447dbd852a3b6bbd8dba3b6f5d400d7e807afcc4fa0c7c615d41a57e8b9afdc1ba66594c5c37b19bd96da8eb3b590084583654fbdd2007cb891ef813bb9fe5424f3cc21e437fe4419f08f2b382e81d4171561a3c099e4287092ab2cae8b72ae8bceaac06ab853e14dd580f9dd9103cc79e47a73605cdd0b92dd1c18236e8e676e8ebf6ac03fabb337a5dd0157463ddd1fd3de0802498a017eb4df4811d928134457f58e345cd40659341f0ca6022050c817104c3d870d847e0b86814311a8cd18c2584b9c613c264130d267998ac98a299aa4955769c761d520da67a908f35c560b2c1248f6927a8e7ead8760cbda651867387e3d50b847b072b5e22ef0e54ee4d26fa62847b917ba579bb2af70afbb627efb6d1ee6daefcdb983522c41c37500eae83d9af891aa88e6aa8aca8c8cac1c0822751372559314298b820aa2a3f5c9c973d8e4acb8d7a131e7e10dc8f4a141ee6cc465d66438d06811f26be85f9c04d70f135eb27d4f4f7a8edaf61e22f51e99fa2e63fb13e46f55f401ffc1ddd704e19f824dcfb3ad9f79875545957f87637fa6a2b7a6c23ba4d7876353a70053a7111bcba009d298c3a1b4e9d898e4dd5361d8b7e1e638d46670f2786c1a229e4d141e4d1178134693f6d53e153496fa217d9c32549d3e306911672bebfd17f15fb18bf4eb7b874d574213a6b1c73765408634b8fbbf70bc7f30eaee93b6a3aeb9f207d9b44ceed45e327c7b2afb6ee008cf940655dc11072af6004fc3b1a88391b4716164cc25c4ec13d722a19793a667816667ab6f2f23c65e6f9b8bb2e048bc9d0cbc072e5e8d530b4b82baf05eb513f9b145be16bc17654d61ed4d85e587b3faaed156deea3a8c157c9dfc75195625df02639fc3439fc1c781795fb77b2f80758515cc4eae25398fc73ac36aea0d285cdbf43ddff84d508533ef76185723b7c7e277a2488754b36761721bcced149f76065732f7aea3ef4572ef0307a2d377aee71ac83f2a1070b10855811d8bd047a54509a9545e78a1554795601aba967e0f76ae8eceae8f05ae874e1f8fa70fc7330c1f340f8bd25d10aa630edde89fc2ecdde9dcc2ebdde072493cd5d9f0f2487a7288690c58791c3872b873bee1e4dd61ea79ded187b92c7ccae95530d2b4f276668666ac44ab7694263a2a9a225fdba1e4de3201ea161427d4d1d5033a15a42e5840aa01c28a3289e5080c89b90073c9a900b3c007226e44870ae608295f0435872357c39fc19b814be18fe207c3e7c2e7c8638113e163e10de05b687b7845787178533c0bcf09cf0e4f084f0a8f0f0704a7850b877b853b87db86db8396814ae15ae122e1b2e112e0af2871f0b3f188e84b38150f8f6f08fa16fc017a18f43ef844e874e865e0d1d0ced0c6d0dad0f2d0fa587d242d34393422342834303437d42dd431d434d43f543354355431542a542c5430542b942d943c1d01da15b4356e872f062f03c78377822b837b88558175c144c0d4e06638329c1e4606fd02dd83cd8083408560996254a07f3071f261e0c468221c5edc19b82df05be0b7c13b812f828f061e042e0fdc0d9c09be0f5c091c08ec09ac02a6279203d309d981a181d181a180c0606fa05ba07da8136811681a681fa819a81aa448540a9405e224f2057e07e9023600782813b085fe09aff32f199ffa2ff3c71ce7fca7f1c1cf31ff2ef02dbfd1bfd6bc16aff527f0698e79fed9fe19fec9fe01f0b46f953fc83fc0388defeaefef68ab6fee6fe268ae7340d8caf0d80fbb7ce7fdbdc432b455bd0de43a728ba82a4ff10bd41321880572e4801c3301263312613fca9189f792003e3b502a3b6d6bf05632846f20046f494ff0cc6f8038cf755ff0f7e0b73901df3610772627ef2060a04ca04ca61ceea041a63169b6236bb605ebb6376fb618ec7056605d2c072d4c2fac026d4c41154c76954c9fba8972ba89cef023f076e472d65435ddd177c2cf844b044b012eaae7ab06eb0152a51d4e320d4e68ce09ce0bce00a54ecdee001702c780a757c317829f815b816bc03756e87728472870a83e2a172e88286a0297aa27ba827e8833e19179a8a8e991e5a12da04b68283a1d7d1552743674317421fa2cb3e0d5d097d17fa257453d80fb285ef0ddf877e7c187d5988fab3043ab552b83a5137dc00fddb0ab4453f27a1ab0503c02074f97030164c40e7a7821970c03cf860517829b10276580736125be00bc95ef84370181c0b1f87514e844fc12ce788f7e01ac107c4457049f3199c7439fc35908eba06ac04179f875bc19d20a8115776c286f56cfa3d736c83ec1e82f43809c623df6970abc24ab846cfd0f5e9657a1517c9a8ef2984574fd10848b3ee25a45dc5b8adc3286628c7cec0480bcb8ec5c80f0a27632e92886e98a106982d4175cc5ed97069207cfb386cfb1866f741cc72848ceb87736f8275bf83753f464dbc4f9c0d1d8175772af3ae8279d3c9be5343a34343c9befd5167ed422d428d517715507de550837961df1ca8caeca104d8f7abe0657089ec7b180803af464567a0ae857d87a3ce7b07dba3ea5b059b90794b048bc2bb0f061341b6e02d41e1d92fd037ef07de81615f0d1c0c6c4557ad41774d47a78d504eed483ead431e2d15281cc80d83e6540ebd15f6bceaff0abd7cdeff2ebc79c67f82ac79089dbe1d5dbf11ddbf0298de4c0593c99ed29fd2a1c3408ab289c300728ca0f70de2b8497e7fa3ff2af63192a2be8b7d34f9775de95757cff7d2c6ce3dc0c1f1b8e375d7fb0d1475890606ce3dc3bd0bb4c2233b0e1ea0bc9ba2bd2b463515239ce15f84111708f70af3ee250ee19e76823883d91277ba8be03279f807ff35b8d8071b074102663707ee968f62b60579e0e5e264e67264e79aa02119ba050cdd0e55d213f441c5887bf150d4ce44d4d02c222db01815b51cf7ed35f0f57e54d91154db9b70f659f2f605dcebbf50eefe91eced0721d46804b5fa70f02fa8d9fc583194470d37a07544f360db60527000ea3b05753e192e9f87aa5f81b5c776f4c109e254f05cf083e06764f31f823eac5812c8e8762827ba280f5632c2eaa54265429561f5c6a0053a4e58bd3f7a7092f2fa2c74e57274a874fbced07ed8fd34564eefa0872fc0eddf847e24b7df426e8f90dd1f86050ac107654115f8a10156648dc24de08cf63087b07a32f97c9476b96372e17061f0edf0d15ef2f631e238d95afaeb3c59fa12ad1585e1aec27596e1dfa072ae746d4e20569d8f26e4067914791505128a10c58952a00cad6125153495c16ffdff7b645d5957d69575655d5957d69575655d5957d69575655d5957d69575655d5957d69575655d59d78d5c5513ffbd5403f2772fd5a3a8a1a9a9a9a5a96d50475157518fa8af6990f8aca221f11c684434269e074d88a6a019684eb4002d895689ad13db28da26be00da81f6a003e8083a2576065d40d7c46ea03be8919844f44ceca5e9ade9a3e9ab49d6f4d3f43718a079d160a08741062f190c36482186180cd50c8b62b887111e464631cac3680f6362181b9771ffb58cff83b8fe4f8d3746d123393a8651713067ca9c45737e9d591f6ae0d4488a4656915b5b6ec5b9756856a85bb74e25f73348a6daefa3faa217fa459084fe11884eea86ae1288feea4c74021da9fb04eda91f052fa03f1ddaa06b1d5a01d9cb2d88e606cd88a64413fae520ccd0388a4606cfc5d0d0c3b399d2e006a9ff0770fd9fe87d9e0d63705fab3b0ee6f83caf71c7b1a936ab6b57d3af8e63258e67db2ad7bab66dafe65b1ab793aa0569ddae64deeecabc3d94797b2afb3ac6752ceb98d531e8f58c69ba32d692d1668cb6617c03c6f75db41926184cbc0e937e2793ffadfcde67f3df47ec884f88e1469c9eb9c333b777f43d3673777b0d9eb9c75d97bb2b82eb9b7c807676b25aa9f451aeee45be96eb1cc7d5ddc8d78ea93b93a93b92ad633d2d7b3d9ea3e3b9d971b2eb65d3c3b1ce8d35693d83ba06750c6a7ba815879a99522386fa917aa0febf443d4d5d451d456d504b513352035427aa45aa822ae0195039522952115400e5234f47ca114f45ca469e244a474a454a122522c523c52245419148e148a148c1488148fe483e90379227f217903bf2e7c8639147220f4772451e040f44ee8bfc299233726fe49e48246247ee8e2446b247ee8a24444291602400ee8cdc16b935724be4e6c84d915ff8cffc1aff89ffc0bfe3dff2aff957fc32ff827fc63fe197f845fe21ff809fe7eff377f93bfc2c3fc3dfe2a7f809fe3a7f951fe347f8417e80ef27f6f1bd7c0fdf0d76f19d6007df0eb6f1ad600bd8cc37818d60bd621d5fcbd7285ee6ab142bf90a6239580696124b88c57c115fa8580032f87c453a9847cce569600e980d66113389197c3a310da41253c114623298444c041388f1c438622c31068c26462946f2118ae1609862a8660891e26170a6a4e8afbf8f21ff519cd72a5ef9708d332e2381335a62e4c610723cc7a93116a33d91103320e642ccc9542215b3355d3103889994b32ae6770ecdb6602ee63e5d311f95b1801095b29810f5b314f524ea6a25b18aaf46dd09d6a21605ebf906d4a7a8d3cda8d8ada8de6da86151cdbbc06ed4f75eb00fd57e00bc020ef243fc30fae028718cbfc68f136fa047de244ea167de46efbccbdfe317d04bff444f7d8cdefa0c3d76995f41bf7d8bbefb1eddf713faf0176e45187af26674e76d91dbc11de8d61008836ce8e3bbd1cf821ce8ee9cc47d91fbd1f1a2ef73c1008f441e850bfe0c2708333c0e43e489fc15a6c80f6b080ac2214514c56096e2f04b0958a694a234dc538628ab9c540e762a4f5420635584b92a13c2635514c26dd514d277351435895a9ada9a3a71a87b5de2fd8b586a1bd4523fbf26b9b8ba46dab82ad9b8b2a2927a7dd2c84f9395859125653036a5c9cba5c8ca2594998b4479396fe4091a75e165c7ccb90861e6fbb59b734422cacec2cdd960e730e63910f163ce5d3b5be46769e7abe4e72ba89ccfc9cf1fa19aa49fdf4385bd4d7e3e859a937e3e82ca3c843a9535ebd859fa7907f9799be1e68da8fd0dcaca6b9593576b234b1b2f5516961ece20e62bf3ce25f34aef3ace9d41ce357d2b4d2b6d3b51116b5bc7b763952d5cefba8c8acbc85f65c47f3dc3336158260cfd4db8ff6eb8f1339dd1713d2d5d3d569bda74753c5b4b63a72aa679aced185b5a7b8e425a5b62ba7bbeaa2cd7e00b516f02c7e34b684db08c109529d60baed35793d7d7501d3b56975edf4cb866175db00bbd212c7e08fdf21afae60438893e3acbcfa1a3dee57f87b5ff811e73ac2dbc2dad7d151df903564ec2dabf7016f1a15f6f216fdf891e16abac2039fb2ef4b7f43647cfdf43defe132c209cfd508cb3a5b19fd0c62e08b3486317255fbbb62e4debc432ca4e4f1996ae408eaea43c2d2d5d5519daf5720d6d65d7c58e67eb192be3069a67a370f6817a18fb41ff0a3d3221298a9e1e7a7930776ffb7a88deb735776b5ff4eccd3aefb4cc3d58b9a3e0ee238c34f6509dfd02677fc0d90d70deb74f015389d4c46989d389196066e2acc4d989731469897313e711e989f31333140b1217262e22168325c4d2c465c4f2c415c4cac4558ad5892f2bd680b58a7589eb890d8a8d899bc066c596c4ad8a6d60bb6247e24ecdaec4dd067b12f72af611fbc101c52be0a0e290e23038a2394a1c53bc4abc461c37785df3063861f0660c278daf27d57727f5fffa7f17f735bfa11123e28e921c373986ce881e5588b13eac39a467e515e200cd9a649f662fe6760f667897c299ff1da8876d84a8922d40d4cd26622321aa6a3dea4cb0966a4f56e16ad4e44a6205aa55b20cf5bb94ea5854f422d4b76401aa7d3efd4a27642fcc25d280ec92d960163ac741f491eca86906a984e8b8298477cfcbbb4714bb1f147f0728feae7de6fb3ef1f67ea23fb989de031a72c3a4c430f87793a2bf5e9fe8e7127fb7d571a56bcc789f43c5eebd7a775cc747edae4e32ac6a9a55da3595667fba76ac5325b3c8b4b3c9b66964dab9cab6e9866d1728db4ad32e55389e5da93cbb5a59561ad675eb46d5119b0ca39a2e953d250dba87ecb95fbbd3f5e621c3965e4fbe166547c709d1663ca93965f0d675389d0967fe2b709f8bf35d66cfd6f9bb337fd8f3377f9e3b7ece189f348836b87b478be76fafbd8f687b1fd2b8ee96fe3e60d8dbb91fef51c41a5c387c87aac66dba3aa5cbb7a87580e9f38de4f3f5cae95ea3c73add31fa6265f44586d133c8e8f3c9eaaed15d9bcf22a4c767783c6efa7b8ae16fafb7c745b9da74b463e468ffbaae8db5a7bbcb3e30cefebaf793d1640f7de3d0278ade7139c2254735e6f7f13812c361e290c141f08ab12fbb8f7600c4fbff5d0af7fdbfb33f2b7766e5eeac775776a57affefbcfb97effce7abf7fd69eaddfe0c7a8f2fdfdf4fc4bbc4b1ea1dfb48bccb14fb9f2f8141fc45de8ff7e57d402f9ec4bbf36ebc2befcc3bf076fc05de96b7e62d790bde8c37e18d7923de9037e0f5781d5e9bd7e2357855fe0cafc42bf2f2bc1c7f8a97e5a578315e9417e18579419e97ff95e7018ff3c7f8c3fc21e27e9e93e700116ef3447e17c8c6433cc0fde00e7e2bbf05dccc6fe2bfd83f836bf64ff60ff6f7c477f655fb1bfb6bfb2bfb8afda57dd9fec2fedcfeccfe045cb23fb62fdaffb02f10e7edbfdbefd9ef8277ecb7edb3f6dfc019fbb4fd967dd27ed33e61bf61bf6e1fb75fb58f1147edc3f641fb00b1cfde6bef01bbed5df60e7b3bb1cdde626f2436d8ebedb5c41afb657b15b1d25e6e2f034bed25f662b0c85e686710f3ed747b9e3dd74e23e6d8b3ed59f64c62863dcd4e554cb5a7d8933593e232398629514c25c4e34df3303d8a1960e67f8859c46c2047602e98873149c7c8ccb71760a4048b317262fc966324c578ae062f6384d761ac3760cc37d99b31fedb300f3bec9d9895dd98a17df67ef00ae6ed08388a997c0df3791c337b0a732c388df93e6b9fc3ecbf03de433d5cb03f202ea2522ea1623e45f57c893aba827afa1695f53daaec4754db2f3643edf95083b7f2db5191211ee609a8d0eca8d608bf07e444053fc473a19e1fe37f417d3f01f2f102bc106abe282f0e4af227d109e5c0d3e88b67781550159d521b3d5397d747ff34221af3a6bc393a4bd0069dd60174e49d7817f49f2009bdd81b1dd99727a33b07a0470751b7a6e81dfd516ad75eec024d509f92883d1f67976786da8b9fad76759cdd1c73177e51cc1efc72b57313bd6fe3ecdcacd53b371bb49b36a93d9c2d8aad84dccbd9aef673761aec8a62b7628f66af669f72e5feebb24fb3d7403ed21e83dd06bba2bcbb433d5bf3b3b1cd8681e52eec3af5f9d86acd4af5d99874b1fc5463217d0a267761e76a1b8bddd7697aaf7512664deea98e51fb9f625ea59507f18198f101e4e5dea8845ebc27ef012f77468574429db48799db00e1e6e6a8a4a664e786fc59d8b93e6aad262a4ed8b932af00370b3b0b379700c551a90551b3f9e0e73ca8e1dca8e44751d10ff207f87da8ef7b50e911ce61e604d47f106e76bcece3161746fed163e32fc9c39fa2ab2eda1fc2c2c2bfefc3be6fa303cfa213df8275df20ebbe06df1e41df1e42f7ee471f0bd34ad76eb3b7a2cfb7a0db37a2f305eb946785118467052be089e5645ce15b89b4ee2232afc30222834ce392ee61de6f42da2bf6fbdfcadc1b242d0e7334b315b334ce9d45225c2fef00a9c69d66aaf1a754e31e3143335b3d7e9a32b57075068da51cd745186fe9eb65988b95e46ac11af2b5c031b670b630f64e65ed3dcadb0770af3d840a101c453548731f476d9c40959c22773bf696fe16f7f1f7c0795496e403fb9fa8b48be4f24f50799f832fb01eb8427c85aafc16b5f91dad19a4d5c54a429afd6654f26de00eb83d4866176ebf1bf59e83dc7e1f7a40d8fd1174c49fd11dc2ee79d12905b19e290a8aa17f4af332c453f07b05ac7d2a832abc1a3aae16a88bfe7b1634423f36c59aa919564eadd1abed407b746e57f47037d8bd07fab9b7727b7ff4f94072fb6074ff307840eef60bb3cb3d7de175d7ea33d56e7d9adea19746979fa93a7bf08ec7dd4f53d7687bbb3befb17befaead771946766decbaf880feb4557ee2ea70882ff07959482ca05fbf970ccdfc28d215f33cccd5a429e610b30dbc792dd7cb64719258246e0e8b99c0e2cd5f19ab18edc91e70f206cc6401337165904a1130f356927562409f98bc152771c54d08e8aaf201ba18c92b4e468044a604c8a4002785c5cc6169ad33035aeae48be6ea2475373dc04c10f066b23869020d55268ba4bece66a9ab709259cc6c969a463e8b73367c359d39e066b454d1991fcfe833e663314fa0af64fca992e76ffe58a27feaaf73bd477bc69375e23d4ddf21de69faee49faf534e629fa0d8d53f41beb53f49d796eaa67df7b8ebe9b86d2569fa4df4e9fa2df51d159d763177582be9986629e9f1f9d81e23d3d7f803e3ddfcc3c894e3a31d34cccb3f3471838e7e78f8e3a3b7facc1b818c61b4c30981845fcd3f563c9fc84fdcc893d737f9afefa5bc9fcb1ae87f95c4c17c6cba78a9752e5e0da5232ce634d27b1cab4a73b7fc3a392abcc8c96144f2e8b99c6e2a45899692c6e8e556f4ffe4a924eb272bdea75aa635427cdea0595bb626659894e31ad299329ccec2ac790f53d9955ae135d23c637a1e93fd720153d548842267594ff7fcbd3ff12d13926153c6926f1fcec35713c0f9be92635f55dce49a3aaed493731334ebce954d1292732e9a4914a3b8976b5d7d6cd8dec13d3d8ad75068a937f629abb439c2cab2e46068a9b64d5432759791ddedbe3f06423c1cac93f3153ab1c7fa7c43578bcdc93686b9b869e6078d8f46c3c8bba3674567cce2ad09b02389b568e73346971981b83bb1a4dff15e44af600dbffbbd9a7d80bf62876b35d6027d801b6836dc456b6856d069bc046b681ad27d6b1b56c0d7b99ad2656b1e58a656c295b0c1681856c01cb60f389743697925c646acb4c365da50b4ca1dc80892a99658c4a0890d900321760904e03e8672401f4a014802e4606406bd68a12009ab2e78d73ff9ddc956a74e67f4556813dcdcaa9d495e2eaacff422c3fcbcb9ea0d495c7d963ec514a5dc9c51e60f70191bb9283cefa17a7fddfc5125898855880b25764fa8a4f9dfa6f3171eabfe047eb7beb2af8967258beb42e832faccfadcf288de563eb23eba2f54feb439d05f03ee5b2bc63bd4d9cb5fe669db6de02a7ac93d69b940ef0ba4a087855a5041cd6f92c0780c86871125a4446cb766b0bb1d9daa4725ad6d359f032a76515e5082c23965a4bacc5465acb7cca6b9947992d69942f209849ccb86166c6e09c5fef658e26cdc35cf51c7e8db9eaf71bc5fbafd309798e7e065efd4285180d9979b2d45a8e915a49a7eaaf56c9276bac7518cdf518d34d34c6e234fddd7496fe7e3a43ff10e6e6a83e435f64a088d3f34fab0c94778877ad7f60fe059728a14764a15ca6d3f3c5f9f9e2f4fc6bd6cfd62f96383bff66760baaec0ee3ecfceca8c308bb07e464f7b307d943e0514a43c9438928795941d4b4382fbf189d94ff24aafd293a255f245e54a113f2c519f9f58d0c9466949cd1025df4026b47a7e377d4a927dd29ed24894ec5efab524efaeb6493c14696c9489d5c3296cebd97a7de4fd627dda7d2e9f6ce99f6b3e002270b6a2e9ba7990f6b2c502c24932c22a72c815b24cb609a15c44ab8473ae865c51ac55ab08e58afd800362a3629361b6c31d80ab669b61bec50bfff1adb63d866e03cfe56cd16fd3ca46937926d37906bd7d1ab11c8d7285ff14ac50ab2ae608932afe3de74304f9957b857666489942c27c5651266689ccac41aad93594628fb8a9403379345666125530e96ac881ea88dce94a3d08152b0da527a8ee3619181255c2cf357ea9087ab53065665f2b0ccbf7a92d2af4aa0568ba06e0b52fe9548bf7a9ce5a6fcab87616299b9722f99d846fddf853e0853e2caedec367408a3fcab6b94b822acfb15d9f67374d647e09fe8b60b94b8f20ed9f5343af214a5ae1c0722a94838f5b0f2e93eea6591be22b2aeb6a3bfa54737102289659d32e96ac52a32c44a957eb59c12b01cbb4a96281667caa23f948599b240911197f99a748deb5e89e36c9945237e49e279de34fb7cf533c44f5fa446c1cd3191de955926ab9577d79275051b55fa94e3dfed9829c11e38f88042669a1c543e3ea6b3cd5ea564aa3754ea99483711f95482bf51c289f4b3c838119cd7a6be083eb63e51996a9fe3ae7e85f85a25585da5dc931fc9dc3f5b1693ee16dc4a79567e42383c01d59b9dd24f6cca3f91d927f763bdf120655b89f5476e74c01330b9201f7aa230d62962b5521ceb9627556251594a3fa908af5722af57633554fa493df49c707b23cab66a46766f81be6c03bb4bbf77a0dc139968d58d0c2f134f9ccc930146da894c3919a193a9c6c016d2ec93548a89e375d7ea69e4f474727906795c9a7c09d95b221dbe4a210dbed6e3ed0ddad9aeab1d5f46bb59387727b1cb60b7628fe67f00331a3f91"));
	qDebug("size = %d, crc = %d", orgData.size(), qChecksum(orgData.constData(), orgData.size()));







}

MainWindow::~MainWindow()
{
	delete ui;
}